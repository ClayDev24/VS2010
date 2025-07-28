#include "include_all.h"
#include <cstdlib>
#include <stdio.h>
#include <fstream>
//#include "ncurses.h"
//#include "ClientNNTP.h"
#include "date/sdate.h"
#include "Statistics2.h"
using namespace std;
using namespace clb;

extern char meses[][13];

void menu();
void menu1();
void menu2();
void menu3();
void menu_config();
bool read_files();
void gerar();
void send();

int get_numeric_value(int begin, int end, string message = "Digite a opção: ");
string get_string_value(string msg = "Digite o nome: ");

void get_current_date();
char current_date_str[50];
void press_any_key();
string get_state(bool test);

CStatistics *m_estat;
sdate *current_date;
HEADER mnuHdr;
string saida;
bool preenchido = false;
int dias_no_periodo;
string period;
string nickname;
string email;
string subject;

int main() {
	clb::PrintColour_("<<_STATISTICS_>>", BRI);

	m_estat = new CStatistics();
	m_estat->m_selection = false;
	mnuHdr = ID_HEADER_NICKNAME;
	current_date = new sdate();
	dias_no_periodo = 7;
	sprintf(current_date_str, "(Data Vigente: %i/%i/%i)", current_date->get_day(), current_date->get_month(), current_date->get_year());
	nickname = "nickname";
	email    = "<seu_nick@seu_provedor.com.br>";
	subject  = "Statísticas...";

	bool done = false;
	char ch;
	do {
		system("clear");
		menu();
		switch(get_numeric_value(1, 11)) {
		case 1: 
			system("clear");
			menu1();
			press_any_key();
			break;
		case 2:		
			{
				//		    CClientNNTP client(*current_date, "news.abusar.org");
			}		
			press_any_key();
			break;
		case 3:
			system("cls");  
			gerar();	
			press_any_key();
			break;
		case 4: 
			system("clear");
			menu2();	
			press_any_key();	
			break;
		case 5: 
			system("clear");
			saida = m_estat->show(mnuHdr, NAME);
			cout << saida << endl;
			press_any_key();
			break;
		case 6: 
			system("clear");
			saida = m_estat->show(mnuHdr, QUANTITY);
			cout << saida << endl;
			press_any_key();
			break;
		case 7:
			system("clear");
			menu3();	
			press_any_key();
			break;
		case 8:
			{
				system("clear");
				cout << "Salvando arquivo \"saida.txt\"..." << endl << endl;
				ofstream outFile("saida.txt");
				if(!outFile) {
					cout << "Arquivo não pode ser salvo..." << endl << endl;
					break;
				}
				outFile << saida << endl;
				outFile.close();
			}
			press_any_key();
			break;
		case 9:
			system("clear");
			{
				send();
			}
			press_any_key();
			break;
		case 10:
			system("clear");
			menu_config();	
			break;
		case 11: 
			cout << "bye!..." << endl;
			done = true;
			break;
		}
	} while(!done);
	delete m_estat;

	system("pause");
	return(0);
}

//Menu Principal:
void menu() {
	cout << "\t*** MENU PRINCIPAL ***  " << current_date_str <<  endl << endl
		<< "1-  Entrar com nova Data Vigente;" << endl
		<< "2-  Fazer Download das Estatísticas na Data Vigente;" << endl
		<< "3-  Gerar Estatísticas;" << endl
		<< "4-  Mudar Cabeçalho;" << endl
		<< "5-  Mostrar Cabeçalho (por Nome);" << endl
		<< "6-  Mostrar Cabeçalho (por Quantidade);" << endl
		<< "7-  Pesquisa Avançada;" << endl
		<< "8-  Salvar Ultimo Resultado;" << endl
		<< "9-  Enviar Ultimo Resultado para o ng Selecionado: " << m_estat->m_selected_ng << ";" << endl
		<< "10- Configurações;" << endl
		<< "11- SAIR." << endl << endl;
}

void menu1() {
	do {
		preenchido = false;
		cout << "Digite o ano ";
		int year = get_numeric_value(1900, 3000, "(yyyy): ");
		cout << "Digite o mês ";
		int month = get_numeric_value(1, 12, "(1 - 12): ");
		cout << "Digite o dia ";
		int day = get_numeric_value(1, 31, "(1 - 31): ");

		delete current_date;
		current_date = new sdate(day, month, year);
	} while(!current_date->valid());

	sprintf(current_date_str, "(Data Vigente: %i/%i/%i)", current_date->get_day(), current_date->get_month(), current_date->get_year());
}

//Mudar cabeçalho:
void menu2() {    
	cout << "\t*** CABEÇALHOS ***" << endl << endl
		<< "1-  " << get_state(mnuHdr == ID_HEADER_NICK_E_EMAIL_E_GROUP) << "Nickname + Email + Grupo;" << endl
		<< "2-  " << get_state(mnuHdr == ID_HEADER_SUBJECT_E_GROUP) << "Assunto + Grupo;" << endl
		<< "3-  " << get_state(mnuHdr == ID_HEADER_NICK_E_EMAIL) << "Nickname + Email;" << endl
		<< "4-  " << get_state(mnuHdr == ID_HEADER_CROSS_GROUPS) << "Grupos Cruzados;" << endl
		<< "5-  " << get_state(mnuHdr == ID_HEADER_NEWSREADER) << "Newsreaders;" << endl
		<< "6-  " << get_state(mnuHdr == ID_HEADER_NICK_E_IP) << "Nickname + Ip;" << endl
		<< "7-  " << get_state(mnuHdr == ID_HEADER_NICKNAME) << "Nickname;" << endl
		<< "8-  " << get_state(mnuHdr == ID_HEADER_SUBJECT) << "Assunto;" << endl
		<< "9-  " << get_state(mnuHdr == ID_HEADER_GROUPS) << "Grupos;" << endl	
		<< "10- " << get_state(mnuHdr == ID_HEADER_HOUR) << "Hora;" << endl
		<< "11- " << get_state(mnuHdr == ID_HEADER_IP) << "Ip;" << endl << endl;

	mnuHdr = (HEADER)get_numeric_value(1, 11, "Digite a opção: ");
}

//Pesquisa Avançada:
void menu3() {
	cout << "\t*** PESQUISA POR ***" << endl << endl
		<< "1- Nickname;" << endl
		<< "2- Grupo;" << endl
		<< "3- Ip;" << endl << endl;

	int opt = get_numeric_value(1, 3, "Digite a opção: ");
	string msg;
	if(opt == 1) {
		opt = (int)ID_HEADER_NICKNAME;
		msg = "Digite o nickname a ser pesquisado: ";
	} else if(opt == 2) {
		opt = (int)ID_HEADER_GROUPS;
		msg = "Digite o grupo a ser pesquisado: ";
	} else {
		opt = (int)ID_HEADER_IP;
		msg = "Digite o ip a ser pesquisado: ";
	}

	string name = get_string_value(msg);

	saida = m_estat->advanced_search(name, (HEADER)opt);	    
	cout << saida << endl;
}

void gerar()
{
	char* file = "Message15Oct.txt";
	//   char file[30];
	char per[25];
	//    sprintf(file, "Message%i%s.txt", current_date->get_day(), meses[current_date->get_month()]);
	sprintf(per, "%i de %s", current_date->get_day(), meses[current_date->get_month() - 1]); 
	period = per;
	try {
		if(!preenchido) {		
			if(!m_estat->m_dayly) {
				if(read_files()) {
					sprintf(file, "ByPeriod.txt");
					sprintf(per, "por periodo\0");
				} else 
					return;
			}
			m_estat->readFile(file, period);
		} else {	    
			m_estat->define_partial();
		}
		if(m_estat->is_empty()) {
			cout << "Nenhuma msg na data..." << endl << endl;
			return;
		}	
		saida = m_estat->modelo1(5);
		cout << saida << endl;
		preenchido = true;
	} catch(NoFile nf) {
		cout << nf.get_message() << endl
			<< "Favor fazer o download (opção 2)..." << endl << endl;
	}
}

bool read_files() {
	ofstream outFile("ByPeriod.txt");
	if(!outFile) {
		cout << "Arquivo ByPeriod.txt não pode ser criado!!" << endl;
		return false;
	}
	sdate _date_tmp = *current_date;
	cout << "Verificando a existência dos arquivos..." << endl << endl;

	char per[15];
	for(int i = 0; i < dias_no_periodo; i++) {
		_date_tmp--;
		if(i < 1)
			sprintf(per, "%i/%i", _date_tmp.get_day(), _date_tmp.get_month());
		char file[25];
		sprintf(file, "Message%i%s.txt", _date_tmp.get_day(), meses[_date_tmp.get_month()]);
		cout << "Arquivo " << file << "... ";	
		ifstream inFile(file);
		if(!inFile) {
			cout << "FALTANDO! Favor fazer download!" << endl << endl;		    
			outFile.close();
			return false;
		}
		cout << "OK!" << endl;
		char buff[1024];
		while(!inFile.getline(buff, sizeof(buff)).eof())
			outFile << buff << endl;
		inFile.close();
	}
	char per2[15];
	sprintf(per2, "%i/%i", _date_tmp.get_day(), _date_tmp.get_month());
	period = per2 + (string)" à " + per;
	outFile.close();
	cout << endl << "Aguarde..." << endl << endl;
	return true;    
}

string get_state(bool test) {
	if(test)
		return "(x) ";
	else 
		return "    ";
}

//Configurações:
void menu_config() {
	const char *xis = "(x)";
	cout << "\t*** MENU CONFIGURAÇÕES ***" << endl << endl
		<< "1-  " << get_state(m_estat->m_view) << "Mostrar Emails e Grupos;" << endl
		<< "2-  " << get_state(!m_estat->m_view)  << "Ocultar Emails e Grupos." << endl
		<< "   ----------------x------------------//" << endl
		<< "3-  " << get_state(m_estat->m_selection) << "Grupo Específico;" << endl
		<< "4-  " << get_state(!m_estat->m_selection) << "Grupo Geral." << endl
		<< "   ----------------x------------------//" << endl
		<< "5-  " << get_state(m_estat->m_dayly) << "Diário;" << endl
		<< "6-  " << get_state(!m_estat->m_dayly) << "Por Período." << endl
		<< "   ----------------x------------------//" << endl
		<< "7-  " << get_state(m_estat->m_mode == ID_HEADER_NICKNAME) << "Nickname;" << endl
		<< "8-  " << get_state(m_estat->m_mode == ID_HEADER_NICK_E_EMAIL) << "Nicknmae + Email;" << endl
		<< "9-  " << get_state(m_estat->m_mode == ID_HEADER_NICK_E_IP) << "Nickname + Ip;" << endl
		<< "   ---------------x--------------------//" << endl
		<< "10- Dados pessoais." << endl
		<< endl;
	switch(get_numeric_value(1, 10)) {
	case 1:
		m_estat->m_view = true;
		break;
	case 2:
		m_estat->m_view = false;
		break;
	case 3:
		m_estat->m_selection = true;
		m_estat->m_selected_ng = get_string_value("Digite o nome do grupo (Ex.: u-br.teste): ");
		break;
	case 4:
		m_estat->m_selection = false;
		break;
	case 5:
		preenchido = false;
		m_estat->m_dayly = true;
		break;
	case 6:
		preenchido = false;
		m_estat->m_dayly = false;
		break;
	case 7:
		m_estat->m_mode = ID_HEADER_NICKNAME;
		break;
	case 8:
		m_estat->m_mode = ID_HEADER_NICK_E_EMAIL;
		break;
	case 9:
		m_estat->m_mode = ID_HEADER_NICK_E_IP;
		break;
	case 10:
		nickname = get_string_value("Digite seu nickname: ");
		email    = "<" + get_string_value("Digite seu email: ") + ">";
		dias_no_periodo = get_numeric_value(1, 30, "Dias no periodo: ");	    
	}
}


void send() {
	CPair *head = new CPair[8];
	head[NICKNAME]   = CPair(ID_HEADER_NICKNAME, new string(nickname));
	head[EMAIL]      = CPair(ID_HEADER_EMAIL, new string(email));
	head[GROUPS]     = CPair(ID_HEADER_GROUPS, new string(m_estat->m_selected_ng));
	int pos = saida.find("\n");
	if(pos != -1)
		subject = saida.substr(0, saida.find("\n"));
	head[SUBJECT]    = CPair(ID_HEADER_SUBJECT, new string(subject));
	subject = "Statisticas...";
	head[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, new string("ClayStat =))"));

	string body("ola...");

	CArticle msg(head, false, saida);
	try {
		//		CNNTPSocket client("news.abusar.org");
		//        client.sendMessage(msg);
	} catch(...) {
	}
}

int get_numeric_value(int begin, int end, string message) {
	char choose[10];
	do {
		cout << message;
		cin >> choose;
		cout << endl;
		int opt = atoi(choose);
		if(opt >= begin && opt <= end)
			return opt;
		cout <<  "opção inválida: " << endl;
	} while(true);
}

string get_string_value(string msg) {
	char name[100];
	cout << msg;
	cin >> name;
	cout << endl;    
	return name;
}

void press_any_key() {
	cout << "Pressione qualquer tecla para voltar ao Menu Principal e tecle <enter>..." << endl;
	char key[5];
	cin >> key;
}




