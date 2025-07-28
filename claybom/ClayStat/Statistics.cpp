#include <iostream>
#include "Statistics.h"
#include "include_all.h"
using namespace std;

// Construction/Destruction
CStatistics::CStatistics() :
	m_selection(false),
	m_view(false),
	m_dayly(true),
	m_mode(ID_HEADER_NICKNAME),
	m_selected_ng("u-br.teste"),
	m_subject(""),
	m_period(""),
	m_totalReplys(0)
{
	vArticlesGeral = new vtMsg();
	vIp            = new vtPairInt();
	vHour          = new vtPairInt();
	vGroups        = new vtPairInt();
	vCross         = new vtPairInt();
	vNickname      = new vtPairInt();
	vSubject       = new vtPairInt();
	vXreader       = new vtPairInt();
	vNickIp        = new vtPairInt();
	vNickEmail     = new vtPairInt();
	vNickEmailNg   = new vtPairInt();
	vSubjectNg     = new vtPairInt();
};

CStatistics::~CStatistics() {
	if(vArticlesGeral->size() > 0) {
		vtMsg::iterator msg;
		for(msg = vArticlesGeral->begin(); msg != vArticlesGeral->end(); msg++)
			delete *msg;	
	}
	vArticlesGeral->clear();

	for(it = vIp->begin(); it != vIp->end(); it++)
		delete *it;
	for(it = vHour->begin(); it != vHour->end(); it++)
		delete *it;
	for(it = vGroups->begin(); it != vGroups->end(); it++)
		delete *it;
	for(it = vCross->begin(); it != vCross->end(); it++)
		delete *it;
	for(it = vNickname->begin(); it != vNickname->end(); it++)
		delete *it;
	for(it = vSubject->begin(); it != vSubject->end(); it++)
		delete *it;
	for(it = vXreader->begin();  it != vXreader->end(); it++)
		delete *it;
	for(it = vNickIp->begin(); it != vNickIp->end(); it++)
		delete *it;
	for(it = vSubjectNg->begin(); it != vSubjectNg->end(); it++)
		delete *it;
	for(it = vNickEmail->begin(); it != vNickEmail->end(); it++)
		delete *it;
	for(it = vNickEmailNg->begin(); it != vNickEmailNg->end(); it++)
		delete *it;	

	delete vArticlesGeral;	
	delete vIp;
	delete vHour;
	delete vGroups;
	delete vCross;
	delete vNickname;
	delete vSubject;
	delete vXreader;
	delete vNickIp;
	delete vSubjectNg;
	delete vNickEmail;
	delete vNickEmailNg;
};

bool CStatistics::is_empty() {
	if(vHour->size() == 0)
		return true;
	else
		return false;
};

void CStatistics::change_vigent(unsigned int header) {
	switch(header) {
	case ID_HEADER_NICKNAME:
		vVigent = vNickname;
		break;
	case ID_HEADER_GROUPS:
		vVigent = vGroups;
		break;
	case ID_HEADER_CROSS_GROUPS:
		vVigent = vCross;
		break;
	case ID_HEADER_SUBJECT:
		vVigent = vSubject;
		break;
	case ID_HEADER_SUBJECT_E_GROUP:
		vVigent = vSubjectNg;
		break;
	case ID_HEADER_NEWSREADER:
		vVigent = vXreader;
		break;
	case ID_HEADER_NICK_E_EMAIL:
		vVigent = vNickEmail;
		break;
	case ID_HEADER_NICK_E_IP:
		vVigent = vNickIp;
		break;
	case ID_HEADER_NICK_E_EMAIL_E_GROUP:
		vVigent = vNickEmailNg;
		break;
	case ID_HEADER_HOUR:
		vVigent = vHour;
		break;
	case ID_HEADER_IP:
		vVigent = vIp;
		break;
	}
};

std::string CStatistics::show(unsigned int header, std::string kind) {
	change_vigent(header);
	if(kind == "name")
		sort(vVigent->begin(), vVigent->end(), NameCompare());
	else if(kind == "quantity")
		sort(vVigent->begin(), vVigent->end(), IntCompare());
	else
		return "NULL";
	std::string str = "Total: ";
	str += utils::_toStr(vVigent->size());

	if(kind == "quantity") {
		int cont = 0;
		for(it = vVigent->begin(); it != vVigent->end(); it++) {
			std::string ordem = utils::_toStr(++cont);
			//case1:
			//ordem.Format("%i%c- %s%s\n", (i + 1), 186, percentage((*it)->get_counter()), (*it)->toString2());
			//out += ordem;			
			//case2:
			str += static_cast<char>(186);
			str += ordem + (*it)->toString() + "\n";
		}
	} else 
		for(it = vVigent->begin(); it != vVigent->end(); it++) 
			str += (*it)->toString() + "\n";

	return str;
};

std::string CStatistics::retorna_ngs_geral() {
	if(vNickname->size()==0)
		return "Grupo inexistente ou digitado erroneamente...";
	std::string str = "";

	sort(vNickname->begin(), vNickname->end(), NameCompare());
	vtPairInt::iterator it2;
	for(it2 = vNickname->begin(); it2 != vNickname->end(); it2++)
		str += pesquisa_pseudo((*it2)->get_value()) + "\n";  		
	return str;
};

std::string CStatistics::pesquisa_pseudo(const std::string &nick) {
	vtPairInt *ngs = retorna_ngs_inscritos(nick, ID_HEADER_NICKNAME);
	std::string str = nick + ":\n:";
	for(it=ngs->begin(); it != ngs->end(); it++) {
		str += "          " + (*it)->toString() + "\n";
		delete *it;
	} 
	delete ngs;

	return str;
};

std::string CStatistics::advanced_search(const std::string &nick, int header) {
	std::string str = "Nenhuma ocorrência encontrada...\n";
	if(header == ID_HEADER_GROUPS)
		str = "";
	else {
		change_vigent(header);
		bool found = false;
		for(it = vVigent->begin(); it != vVigent->end(); it++)
			if((*it)->get_value()==nick) {
				found = true;
				break;
			}
		if(found)
			str = (*it)->toString() + ":\n";
		else 
			return str;
	}

	vtPairInt *ngs = retorna_ngs_inscritos(nick, header);	
	for(it = ngs->begin(); it != ngs->end(); it++) {
		std::string ng = (*it)->get_value();
  		str += (*it)->toString() + ":\n";
  		int cont = 1;
		vtMsg::iterator itm;
  		for(itm = vArticlesGeral->begin(); itm != vArticlesGeral->end(); itm++) {		
			std::string nick2 = (*itm)->get_header(header);
			if(nick==nick2) {
				std::string ng2 = (*itm)->get_header(ID_HEADER_GROUPS);
				if(ng==ng2) {
					std:string s = utils::_toStr(cont++);
					s += (*itm)->toString2();
				    str += s;
				}
			}
		}
		delete *it;
	}
	if(ngs->size() == 0) 
		return "Nenhuma ocorrência encontrada...\n";
	delete ngs;

	return str;
};

vtPairInt* CStatistics::retorna_ngs_inscritos(const std::string &nick, const int &hdr) {
	vtPairInt *vpi = new vtPairInt();
	vtMsg::iterator itm;
	for(itm = vArticlesGeral->begin(); itm != vArticlesGeral->end(); itm++) {
		std::string nome2 = (*itm)->get_header(hdr);
		if(nick==nome2) {		  
			CPairInt *pi = new CPairInt(new std::string((*itm)->get_header(ID_HEADER_GROUPS)));
			vpi->push_back(pi);
		}	  
	}
	put_together(vpi);
	return vpi;
};

std::string CStatistics::postagem(const std::string &s) {
	sort(vHour->begin(), vHour->end(), NameCompare());
	int index = 0;
	if(s == "primeira")
		it = vHour->begin();
	if(s == "ultima")
		it = vHour->end() - 1;
	std::string hour = (*it)->get_value();
	vtMsg::iterator msg;
	for(msg = vArticlesPartial->begin(); msg != vArticlesPartial->end(); msg++) {
		std::string hour2 = (*msg)->get_header(ID_HEADER_HOUR);
		if(hour2 == hour) {
			return (*msg)->toString();
		}
	}
	return "NULL";
};
  	  	
vtStr CStatistics::top_happen_key(int qts, unsigned int header) {
	change_vigent(header);
	sort(vVigent->begin(), vVigent->end(), IntCompare());
	vtStr vetor;
	vtPairInt::iterator fim;
	fim = vVigent->begin() + qts;
	if(fim > vVigent->end())
		fim = vVigent->end();
	for(it = vVigent->begin(); it != fim; it++)
		vetor.push_back((*it)->toString());		  
	return vetor;
};
	  
std::string CStatistics::top_happen(int qts, unsigned int header) {
	change_vigent(header);
	std::string str;
	sort(vVigent->begin(), vVigent->end(), IntCompare());
	vtPairInt::iterator fim;
	vtPairInt::iterator it2;
	vtPairInt::iterator it3;
    fim = vVigent->begin() + qts;
	if(fim > vVigent->end())
		fim = vVigent->end();
	int cont = 0;
	for(it2 = vVigent->begin(); it2 != fim; it2++) {
		std::string ordem = utils::_toStr((++cont);
		ordem += static_cast<char>(186);
		ordem += percentage((*it2)->get_counter());
		ordem += (*it2)->toString2();
		str   += ordem;
		if((header == ID_HEADER_NICKNAME) && m_view) {
			str += "     com os seguintes emails:\n";
			for(it3 = vNickEmail->begin(); it3 != vNickEmail->end(); it3++) {
				if(((*it3)->get_value()).find((*it2)->get_value()) != -1)
					str += "     " + (*it3)->toString2() + "\n";			
			}//for
			if(!m_selection) {
				str += "     e para os seguintes grupos:\n";
				str += pesquisa_pseudo((*it2)->get_value()) + "\n";
			}//if	    	
		}//if 
	}//for
	return str + "\n\n";
};

std::string CStatistics::percentage(int i) {
	float source  = ((i*100.0)/vHour->size());
	std::string s = utils::_toStr(source);
	return s; 
};
//Horário de pico:
std::string CStatistics::pico() {
	vtPairInt *vpi = new vtPairInt();
    std::string str;
	for(it = vHour->begin(); it != vHour->end(); it++) {
		str = (*it)->get_value();
//		vpi->push_back(new CPairInt(new std::string(out.Left(2))));
	}
	put_together(vpi);
	sort(vpi->begin(), vpi->end(), NameCompare());
	if(m_selection)
		if(m_dayly)
			str = "***Horario de pico! (\"o\"=1 msgs):***\n \n";
		else
			str = "***Horario de pico! (\"o\"=10 msgs):***\n \n";
	else 
        if(m_dayly)
			str = "***Horario de pico! (\"o\"=10 msg):***\n \n";
		else
			str = "***Horario de pico! (\"o\"=100 msgs):***\n \n";
	for(it=vpi->begin(); it!=vpi->end(); it++) {
		int users = (*it)->get_counter();
		char user[15];
		sprintf(user, "%4d msgs - ", users);
		str += (*it)->get_value() + "hs -" + user;
		if(m_selection) {
			if(!m_dayly)
				users = users / 10;
		} else {
			if(m_dayly)
				users = users / 10;
			else
				users = users / 100;
		}

		for(int i2=0; i2<users; i2++)
			str += "o";
		str += "\n";
		delete *it;
	}
	vpi->clear();
	delete vpi;

	return str;
};

void CStatistics::readFile(std::string file_name) {	
	vtMsg::iterator msg;
	for(msg = vArticlesGeral->begin(); msg != vArticlesGeral->end(); msg++)
		delete *msg;	
	vArticlesGeral->clear();

	vtPairInt::iterator itpi;
	for(itpi = vCross->begin(); itpi != vCross->end(); itpi++)
	    delete *itpi;
	vCross->clear();
	
	vtStr verify_repeated;	

    char buff[1024];
    ifstream infile(file_name);
	std::string s = "O arquivo: \"" + file_name + "\" nao exite.\nTecle 'CTRL+D' para fazer o download...\n";
    if (!infile)
		throw NoFile(s.c_str());
	vtStr ArquivoLinhas;
    while (!infile.getline(buff, sizeof(buff)).eof())
		ArquivoLinhas.push_back(buff);
//    infile.close();
//	CString line("");

	for(int i=0; i<ArquivoLinhas.size(); i++) {
	//while (!infile.getline(buff, sizeof(buff)).eof()) {
		std::string line("");
//		if(infile.eof()) break;
//		line = buff;

		CPair *headers = new CPair[8];
		bool ref = false;
		std::string *value;
		std::string *xreader = NULL;
		std::string *cross   = NULL;
		std::string *hour    = NULL;

		while(line.find("Xref:") == -1) {

			line = ArquivoLinhas.at(i++);
//		    line = line.Left(line.GetLength() - 1);
			//infile.getline(buff, sizeof(buff));
			//line = buff;
			//if(infile.eof()) break;

			if(line.find(from_key) != -1) {
				if(line.find("\"") == 6) {
					CTokenizer tokens((string)line, "\"");
					int n_tok = tokens.get_size();
					value = new std::string(tokens.get_at(2).c_str());
					
					headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
					if(n_tok > 1) {
						CTokenizer tokens((string)line, " ");
						n_tok = tokens.get_size();
					    value = new std::string(tokens.get_at(n_tok). c_str());
						headers[EMAIL] = CPair(ID_HEADER_EMAIL, value);
					}
				} else if(line.find("(") != -1) {
					line = line.Mid(6);
					int ocorrencia = line.Find('(');
					std::string  s = line.Left(ocorrencia - 1);
					value = new std::string(s);
					headers[EMAIL] = CPair(ID_HEADER_EMAIL, value);
					s = line.Mid(ocorrencia + 1, (line.GetLength() - (ocorrencia + 2)));					
					value = new std::string(s);
					headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
				} else {
					if(line.find('<') != -1) {					
					    //line = line.Right(line.GetLength() - 6);
						line = line.Mid(6);
					    int ocorrencia = line.find('<');
					    std::string  s = line.Left(ocorrencia - 1);
					    value = new std::string(s);
						headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
					    s = line.Mid(ocorrencia + 1, (line.GetLength() - (ocorrencia + 2)));					
					    value = new std::string(s);
						headers[EMAIL] = CPair(ID_HEADER_EMAIL, value);
					} else {
						value = new std::string(line = line.Right(line.GetLength() - 6));
						headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
						headers[EMAIL]    = CPair(ID_HEADER_EMAIL, new std::string("NULL"));
					}
				}
			} else if(line.find(ngs_key) != -1) { 
				value = new std::string(line.Mid(12));
				headers[GROUPS] = CPair(ID_HEADER_GROUPS, value);
			} else if(line.find(xtrace_key) != -1) {				
				//line = line.Right(line.GetLength() - 9);				
				line = line.Mid(9);				
				CTokenizer tokens((string)line, " ");			    
			    std:string *ip = new std::string(tokens.get_at(4).c_str());			
			    hour = new std::string(tokens.get_at(tokens.get_size() - 1).c_str());

				headers[HOUR] = CPair(ID_HEADER_HOUR, hour);
				headers[IP]   = CPair(ID_HEADER_IP, ip);
			} else if(line.find(subject_key) != -1) {
				value = new std::string(line.Mid(9));//line.Right(line.GetLength() - 9));				
				headers[SUBJECT] = CPair(ID_HEADER_SUBJECT, value);
			} else if(line.find(xreader_key) != -1) {
				//CString tmp = line.Right(line.GetLength() - 14);				
				line = line.Mid(14);
				if(line.find("Microsoft") != -1)
					xreader = new std::string(line.Left(29));
				else if(line.find("Mozilla") != -1)
					xreader = new std::string(line.Left(11));
				else if(line.find("Forte Agent") != -1)
					xreader = new std::string(line.Left(16));
				else if(line.find("MICE BeOS") != -1)
					xreader = new std::string(line.Left(25));
				else if(line.find("Sylpheed") != -1)
					xreader = new std::string(line.Left(20));
				else 
					xreader = new std::string(line);
				headers[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, xreader);
			} else if(line.find("User-Agent:") != -1) {
				//CString tmp = line.Right(line.GetLength() - 12);								
				line = line.Mid(12);
				if(line.find("Mozilla") != -1)
					xreader = new std::string(line.Left(11));
				else if(line.find("Gnus") != -1)
					xreader = new std::string(line.Left(8));
				else if(line.find("Opera") != -1)
					xreader = new std::string(line.Left(9));
				else if(line.find("Pan") != -1)
					xreader = new std::string(line.Left(8));
				else if(line.find("newsSync") != -1)
					xreader = new std::string(line.Left(21));
				else 
					xreader = new std::string(line);				
				headers[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, xreader);
			} else if(line.find(msgid_key) != -1) {	
				//value = new CString(line.Right(line.GetLength() - 12));
				value = new std::string(line.Mid(12));
				headers[MSGID] = CPair(ID_HEADER_MSGID, value);
			} else if(line.find(ref_key) != -1) {		
				ref = true;
			} 
		}//while 1..  	
//		if(infile.eof()) break;
		bool repeteco = false;	
		std::string grupo = headers[GROUPS].get_value();				
		if(grupo.find(",") != -1) {
			std::string hora  = headers[HOUR].get_value();				
			std::string both = grupo + " " + hora;
			for(int i = 0; i < verify_repeated.size(); i++) {
				std::string str = verify_repeated.at(i);
				if(both == str) {
					repeteco = true;
					break;
				}//if
			}//for
			if(verify_repeated.size() == 0)
				verify_repeated.push_back(both);
			if(!repeteco) {
				verify_repeated.push_back(both);
				cross = new std::string(grupo);
			} else {
				delete []headers;
				headers = 0;
				continue;
			}//else
		}
		if(xreader == NULL) {
			xreader = new std::string("indefinido");
			headers[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, xreader);
		}
		if(cross != NULL) {
			CTokenizer tokens((string)*cross, ",");
			*cross = "\n        " + *cross;				  
			int n_tok = tokens.get_size();	
			for(int i = 1; i <= n_tok; i++) {
				std::string s = tokens.get_at(i).c_str();					  
				//*cross += "                    " + s + ",\n";
				CPair *hdrs = new CPair[8];
				hdrs[NICKNAME] = CPair(ID_HEADER_NICKNAME, new std::string(headers[NICKNAME].get_value()));
				hdrs[EMAIL]   = CPair(ID_HEADER_EMAIL,  new std::string(headers[EMAIL].get_value()));
				hdrs[GROUPS] = CPair(ID_HEADER_GROUPS, new std::string(s));
			    hdrs[HOUR]   = CPair(ID_HEADER_HOUR,  new std::string(headers[HOUR].get_value()));
				hdrs[IP]     = CPair(ID_HEADER_IP,     new std::string(headers[IP].get_value()));
				hdrs[SUBJECT]  = CPair(ID_HEADER_SUBJECT, new std::string(headers[SUBJECT].get_value()));
				hdrs[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, new std::string(headers[NEWSREADER].get_value()));
				hdrs[MSGID]      = CPair(ID_HEADER_MSGID,  new std::string(headers[MSGID].get_value()));
				vArticlesGeral->push_back(new CArticle(hdrs, ref, ""));
			}
			vCross->push_back(new CPairInt(cross));
			delete []headers;				  
			headers = 0;
		} else 				  
		vArticlesGeral->push_back(new CArticle(headers, ref, ""));			  
    }//while 2..
	infile.close();
	put_together(vCross);
	define_partial();		   
};

void CStatistics::define_partial(void) {
	//vArticlesPartial = new vtMsg();

	if(m_selection) {				
		vArticlesPartial = new vtMsg();
		vtMsg::iterator msg;
		for(msg = vArticlesGeral->begin(); msg != vArticlesGeral->end(); msg++)
			if((*msg)->get_header(ID_HEADER_GROUPS) == m_selected_ng)
				vArticlesPartial->push_back(*msg);			
	} else
		vArticlesPartial = vArticlesGeral;
	fill();	
};
	
void CStatistics::fill() {
	preenche();					
	put_together(vNickname);	
	put_together(vSubject);	
	put_together(vGroups);	
	put_together(vXreader);							
	put_together(vSubjectNg);							
	put_together(vNickEmail);						
    put_together(vNickIp);		
	put_together(vNickEmailNg);			
	put_together(vIp);		
    define_quantity();
}; //fill

void CStatistics::preenche() {
    for(it = vIp->begin(); it != vIp->end(); it++)
		delete *it;
	for(it = vHour->begin(); it != vHour->end(); it++)
		delete *it;
	for(it = vGroups->begin(); it != vGroups->end(); it++)
		delete *it;
	//for(it = vCross->begin(); it != vCross->end(); it++)
	//	delete *it;
	for(it = vNickname->begin(); it != vNickname->end(); it++)
		delete *it;
	for(it = vSubject->begin(); it != vSubject->end(); it++)
		delete *it;
	for(it = vXreader->begin(); it != vXreader->end(); it++)
		delete *it;
	for(it = vNickIp->begin(); it != vNickIp->end(); it++)
		delete *it;
	for(it = vSubjectNg->begin(); it != vSubjectNg->end(); it++)
		delete *it;
	for(it = vNickEmail->begin(); it != vNickEmail->end(); it++)
		delete *it;
	for(it = vNickEmailNg->begin(); it != vNickEmailNg->end(); it++)
		delete *it;
	vIp->clear();	
	vHour->clear();
	vGroups->clear();
	//vCross->clear();
	vNickname->clear();
	vSubject->clear();
	vXreader->clear();
	vNickIp->clear();
	vSubjectNg->clear();
	vNickEmail->clear();
	vNickEmailNg->clear();
	
	m_totalReplys = 0;

	vtMsg::iterator msg;	
  	for(msg = vArticlesPartial->begin(); msg != vArticlesPartial->end(); msg++) {		
		std::string from  = (*msg)->get_header(ID_HEADER_NICKNAME);
        std::string sender = (*msg)->get_header(ID_HEADER_EMAIL);
        std::string ngs     = (*msg)->get_header(ID_HEADER_GROUPS);
        std::string subject = (*msg)->get_header(ID_HEADER_SUBJECT);
        std::string reader  = (*msg)->get_header(ID_HEADER_NEWSREADER);
        std::string hour   = (*msg)->get_header(ID_HEADER_HOUR);
        std::string ip    = (*msg)->get_header(ID_HEADER_IP);

		vNickname->push_back(new CPairInt(new std::string(from)));
		vNickIp->push_back(new CPairInt(new  std::string(from + " - (" + ip + ")")));
		vNickEmail->push_back(new CPairInt(new std::string(from + " - " + sender)));
		vNickEmailNg->push_back(new CPairInt(new std::string(from + " - " + sender + " - " + ngs)));
		vGroups->push_back(new CPairInt(new  std::string(ngs)));				
		vSubject->push_back(new CPairInt(new std::string(subject)));
		vSubjectNg->push_back(new CPairInt(new std::string(subject + " - " + ngs)));
		vHour->push_back(new CPairInt(new std::string(hour)));
		vXreader->push_back(new CPairInt(new std::string(reader)));
		vIp->push_back(new CPairInt(new  std::string(ip)));
		
		if((*msg)->is_thread())
			m_totalReplys++;
	}//for
};//preenche

void CStatistics::put_together(vtPairInt *orig) {
	vtPairInt *vpi = new vtPairInt();
    for(it = orig->begin(); it != orig->end(); it++) {
		std::string s = (*it)->get_value();
		bool contem = false;
		vtPairInt::iterator it2;
		for(it2 = vpi->begin(); it2 != vpi->end(); it2++) {
			std::string s2 = (*it2)->get_value();
			if(s == s2) {
				contem = true;
				break;
			}
		}//for
		if(contem)
			(*it2)->increment_counter();
		else
			vpi->push_back(new CPairInt(new std::string((*it)->get_value())));
		delete *it;
	}//for
	orig->clear();
	orig[0] = vpi[0];
	delete vpi;
};

void CStatistics::define_quantity(void) {
	m_totalNickEmail = vNickEmail->size();
  	m_totalNickname  =  vNickname->size();
  	m_totalXreader   =   vXreader->size();
  	m_totalSubject   =   vSubject->size();
  	m_totalNews      =      vGroups->size();
  	m_totalMsgs      =      vHour->size();
  	m_totalIps       =        vIp->size();
	m_totalNovos     = m_totalMsgs - m_totalReplys;  	
  	m_totalX_Msgs    = retornaXPostingsTotal();
};

int CStatistics::retornaXPostingsTotal(void) {
/*	int out = 0;
	for(it = vGroups->begin(); it != vGroups->end(); it++) {
  		CString s = *(*it)->get_value();
  		if(s.Find(",") != -1) {
			out += (*it)->get_counter();
			CPairInt *pi2 = new CPairInt(new CString(s.Left(pos) + ",\n                    " +
				s.Right(pos2)), (*it)->get_counter());
			vCross->push_back(pi2);
		}
	}
	m_totalCrossGroups = vCross->size();
	return out;
*/
	int i=0;
//	put_together(vCross);
	for(it = vCross->begin(); it != vCross->end(); it++) {
  		std::string s = (*it)->get_value();
  		//if(s.Find(",") != -1) {
			i += (*it)->get_counter();
		//	CPairInt *pi2 = new CPairInt(new CString(s.Left(pos) + ",\n                    " +
		//		s.Right(pos2)), (*it)->get_counter());
		//	vCross->push_back(pi2);
		//}
	}
	m_totalX_Groups = vCross->size();
	return i;
};

std::string CStatistics::modelo1(const int &_qnt)
{
	std::string out = "";	
	std::string s;
	int pos = m_selected_ng.ReverseFind('.');
	std::string ng = m_selected_ng.Right(m_selected_ng.GetLength() - pos);
	m_subject = "## Estatísticas " + m_period;

    if(!m_selection)
		out += m_subject + " news.abusar (geral) ##\n";
	else
		out += m_subject + " " + ng + " ##\n";
	m_subject = out;

	s.Format("=Total de msgs:  %i (novas + repleiadas)\n", m_totalMsgs);
	out += s;
	s.Format("=So as Novas  :  %i\n", m_totalNovos);
	out += s;
	s.Format("=So os threads:  %i\n", m_totalReplys);
	out += s;

    if(!m_selection) {
		s.Format("=Total de msgs cruzadas: %i\n", m_totalX_Msgs);
		out += s;
	}      
	s.Format("=Total de grupos: %i\n \n", m_totalGroups);
    out += s;
    if(m_selection) {
		s.Format("*****Os %i maiores postadores do %s*****\n \n", _qnt, ng);
		out += s;
	} else {
		s.Format("*****Os %i maiores postadores da net*****\n \n", _qnt);
		out += s;
	}


    if(m_mode == ID_HEADER_NICKNAME) 
		out += top_happen(_qnt, ID_HEADER_NICKNAME);
	else if(m_mode == ID_HEADER_NICK_E_EMAIL)
		out += top_happen(_qnt, ID_HEADER_NICK_E_EMAIL);
    else if(m_mode == ID_HEADER_NICK_E_IP)
		out += top_happen(_qnt, ID_HEADER_NICK_E_IP);

    if(!m_selection) {
		s.Format(" \n****Os 40 grupos mais badalados(%i total)****\n \n", m_totalNews);
		out += s + top_happen(40, ID_HEADER_GROUPS);
		s.Format(" \n****Os %i grupos Cruzados mais postados(%i total)****\n \n", _qnt, m_totalX_Groups);
		out += s + top_happen(_qnt, ID_HEADER_CROSS_GROUPS);
    }
	s.Format(" \n***Os %i maiores threads(%i total)\n \n", _qnt, m_totalReplys);
	out += s + top_happen(_qnt, ID_HEADER_SUBJECT_E_GROUP);

	s.Format(" \n***Os \"Newsreaders\" mais usados..(em %%) (total - %i)\n \n", m_totalXreader);
    out += s + top_happen(100, ID_HEADER_NEWSREADER);

	out += " \n";
    out += pico();

    if(m_dayly) {
		s.Format(" \n**Primeira msg %s**\n \n", m_period);
		out += s;
		out += postagem("primeira");				
		s.Format(" \n*Ultima msg %s*\n \n", m_period);
		out += s;
		out += postagem("ultima");		
    }
	if(m_dayly)
	    s.Format(" \n* Total de msgs do dia: %i *\n ", m_totalMsgs);
	else
		s.Format(" \n* Total de msgs do período %s: %i *\n ", m_period, m_totalMsgs);

    out += s;

    if(!m_selection) {
		s.Format("# %i Usuarios (nicks iguais) ng.geral na data#\n ", m_totalNickname);
		out += s;
		s.Format("# %i Usuarios (nicks iguais, email's diferentes) ng.geral na data#\n \n ", m_totalNickEmail);
        out += s;
    }     

    if(m_selection) {
		s.Format("%i na data#\n", m_totalNickEmail);
        out += s;
        if(m_dayly) {
			s.Format("%i e ngs postados por eles na data#\n\n", m_totalNickname);
			out += s;
			out += retorna_ngs_geral();
		}
    }
    out += "\n---X--- FIM ---X---\n";                 	                 
	return out;
}


