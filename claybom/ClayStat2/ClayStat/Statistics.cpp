// CStatistics.cpp: implementation of the CCStatistics class.
#include "Statistics.h"
#include <iostream>

using namespace std;
using namespace clb;

bool NameCompare(const CPairInt *x, const CPairInt *y) {
    return *x->get_value() < *y->get_value();
}

bool IntCompare(const CPairInt *x, const CPairInt *y) {
    return x->get_counter() > y->get_counter();
}

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

void CStatistics::change_vigent(HEADER header) {
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
    }	
};

string CStatistics::show(HEADER header, int kind) {
	change_vigent(header);
	if(kind == NAME)
		sort(vVigent->begin(), vVigent->end(), NameCompare);
	else if(kind == QUANTITY)
		sort(vVigent->begin(), vVigent->end(), IntCompare);
	else
		return "NULL";
	string out("");
    char buff[100];
	sprintf(buff, "Total: %d\n", vVigent->size());
    out += buff;

	if(kind == QUANTITY) {
		int cont = 0;
		for(it = vVigent->begin(); it != vVigent->end(); it++) {
			string ordem("");
			//case1:
			//ordem.Format("%i%c- %s%s\n", (i + 1), 186, percentage((*it)->get_counter()), (*it)->toString2());
			//out += ordem;
			//case2:
			sprintf(buff, "%i%c- ", (++cont), 186);
			out += buff + (*it)->toString() + "\n";
		}
	} else {
		for(it = vVigent->begin(); it != vVigent->end(); it++) {
			out += (*it)->toString() + "\n";
		}
	}
	return out;
};

string CStatistics::retorna_ngs_geral(void) {
	if(vNickname->size() == 0)
		return "Grupo inexistente ou digitado erroneamente...";
	string out("");

	sort(vNickname->begin(), vNickname->end(), NameCompare);
	vtPairInt::iterator it2;
	for(it2 = vNickname->begin(); it2 != vNickname->end(); it2++)
		out += pesquisa_pseudo(*(*it2)->get_value()) + "\n";
	return out;
};

string CStatistics::pesquisa_pseudo(const string &nick) {
	vtPairInt *ngs = retorna_ngs_inscritos(nick, ID_HEADER_NICKNAME);
	string out = nick + ":\n:";
	for(it = ngs->begin(); it != ngs->end(); it++) {
		out += "          " + (*it)->toString() + "\n";
		delete *it;
	}
	ngs->clear();
	delete ngs;
	return out;
};

string CStatistics::advanced_search(const string &nick, HEADER header) {
    string out("Nenhuma ocorrência encontrada...\n");
    if(header == ID_HEADER_GROUPS) {
	out = "";
    } else {
	change_vigent(header);
	bool found = false;
	for(it = vVigent->begin(); it != vVigent->end(); it++) {
	    if(*(*it)->get_value() == nick) {
		found = true;
		break;
	    }
	}
	if(found)
	    out = (*it)->toString() + ":\n";
	else
	    return out;
    }
    vtPairInt *ngs = retorna_ngs_inscritos(nick, header);
    for(it = ngs->begin(); it != ngs->end(); it++) {
	string ng = *(*it)->get_value();
  	out += (*it)->toString() + ":\n";
  	int cont = 1;
	vtMsg::iterator itm;
  	for(itm = vArticlesGeral->begin(); itm != vArticlesGeral->end(); itm++) {
	    string nick2 = (*itm)->get_header(header);
	    if(nick == nick2) {
		string ng2 = (*itm)->get_header(ID_HEADER_GROUPS);
		if(ng == ng2) {
		    string str;
            	    char buff[100];
		    sprintf(buff, "\t%i - \n", cont++);		    
		    out += buff;
		    out += (*itm)->toString() + "\n";
		}
	    }
	}
	delete *it;
    }
    if(ngs->size() == 0)
	return "Nenhuma ocorrência encontrada...\n";
    ngs->clear();
    delete ngs;
    return out;
};

vtPairInt* CStatistics::retorna_ngs_inscritos(const string &nick, const int &hdr) {
	vtPairInt *vpi = new vtPairInt();
	vtMsg::iterator itm;
	for(itm = vArticlesGeral->begin(); itm != vArticlesGeral->end(); itm++) {
		string nome2 = (*itm)->get_header((HEADER)hdr);
		if(nick == nome2) {
			CPairInt *pi = new CPairInt(new string((*itm)->get_header(ID_HEADER_GROUPS)));
			vpi->push_back(pi);
		}
	}
	put_together(vpi);
	return vpi;
};

string CStatistics::postagem(const string &s) {
	sort(vHour->begin(), vHour->end(), NameCompare);
	//int index = 0;
	if(s == "primeira")
		it = vHour->begin();
	if(s == "ultima")
		it = vHour->end() - 1;
	string hour = *(*it)->get_value();
	vtMsg::iterator msg;
	for(msg = vArticlesPartial->begin(); msg != vArticlesPartial->end(); msg++) {
		string hour2 = (*msg)->get_header(ID_HEADER_HOUR);
		if(hour2 == hour) {
			return (*msg)->toString();
		}
	}
	return "NULL";
};

vtStr CStatistics::top_happen_key(int qts, HEADER header) {
	change_vigent(header);
	sort(vVigent->begin(), vVigent->end(), IntCompare);
	vtStr vetor;
	vtPairInt::iterator fim;
	fim = vVigent->begin() + qts;
	if(fim > vVigent->end())
		fim = vVigent->end();
	for(it = vVigent->begin(); it != fim; it++)
		vetor.push_back((*it)->toString());
	return vetor;
};

string CStatistics::top_happen(int qts, HEADER header) {
    change_vigent(header);
    string out("");
    sort(vVigent->begin(), vVigent->end(), IntCompare);
    vtPairInt::iterator fim;
    vtPairInt::iterator it2;
    vtPairInt::iterator it3;
    fim = vVigent->begin() + qts;
    if(fim > vVigent->end())
	fim = vVigent->end();
    int cont = 0;
    for(it2 = vVigent->begin(); it2 != fim; it2++) {
	char ordem[10];
	sprintf(ordem, "%i", ++cont);
	out += ordem;
	sprintf(ordem, "%c-", 186);
	out += ordem;
	out += percentage((*it2)->get_counter());
	out += (*it2)->toString2();
//	sprintf(ordem, "%s%s", percentage((*it2)->get_counter()).c_str(), (*it2)->toString2().c_str());
        out += "\n";
	if((header == ID_HEADER_NICKNAME) && m_view) {
	    out += "     com os seguintes emails:\n";
	    for(it3 = vNickEmail->begin(); it3 != vNickEmail->end(); it3++) {
		if((*(*it3)->get_value()).find(*(*it2)->get_value()) != -1)
		    out += "     " + (*it3)->toString2() + "\n";
		}//for
		if(!m_selection) {
		out += "     e para os seguintes grupos:\n";
		out += pesquisa_pseudo(*(*it2)->get_value()) + "\n";
	    }//if
	}//if
    }//for
    return out + "\n\n";
};

string CStatistics::percentage(int i) {
	float source = ((i * 100.0) / vHour->size());
	char buff[10];
	sprintf(buff, "%*.*f%%", 5, 2, source);
	return (string)buff;
};

//Horário de pico:
string CStatistics::pico(void) {
	vtPairInt *vpi = new vtPairInt();
    string out("");
    for(it = vHour->begin(); it != vHour->end(); it++) {
	out = *(*it)->get_value();
	vpi->push_back(new CPairInt(new string(out.substr(0, 2))));	
    }
    put_together(vpi);
    sort(vpi->begin(), vpi->end(), NameCompare);
    if(m_selection)
	if(m_dayly)
	    out = "***Horario de pico! (\"o\"=1 msgs):***\n \n";
	else
	    out = "***Horario de pico! (\"o\"=10 msgs):***\n \n";
	else
    	    if(m_dayly)
		out = "***Horario de pico! (\"o\"=10 msg):***\n \n";
	    else
		out = "***Horario de pico! (\"o\"=100 msgs):***\n \n";
    for(it = vpi->begin(); it != vpi->end(); it++) {
	int users = (*it)->get_counter();
	char user[15];
	sprintf(user, "%4d msgs - ", users);
	out += *(*it)->get_value() + "hs -" + user;
	if(m_selection) {
	    if(!m_dayly)
		users = users / 10;
	} else {
	    if(m_dayly)
		users = users / 10;
	    else
		users = users / 100;
	}
	for(int i2 = 0; i2 < users; i2++)
	    out += "o";
	out += "\n";
	delete *it;
    }
    vpi->clear();
    delete vpi;
    return out;
};

void CStatistics::readFile(string file_name, string period) {	
    m_period = period;
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
    ifstream infile(file_name.c_str());
    if (!infile) {
	string str("O arquivo ");
        str.append(file_name);
        str.append(" nao existe!");
        const char *ch = str.c_str();
	throw NoFile(ch);
    }
/*	vtStr ArquivoLinhas;
    while (!infile.getline(buff, sizeof(buff)).eof())
		ArquivoLinhas.push_back(buff);
*/		
//    infile.close();
//	string line("");

//	for(unsigned int iii = 0; iii < ArquivoLinhas.size(); iii++) {
    while (!infile.getline(buff, sizeof(buff)).eof()) {
	string line("");
	if(infile.eof()) break;
	line = buff;				
		
	CPair *headers = new CPair[8];
	bool ref = false;
	string *value;
	string *xreader = NULL;
	string *cross   = NULL;
	string *hour    = NULL;
		
	while(line.find("Xref:") == -1) {
//	  line = ArquivoLinhas.at(iii++);
	    infile.getline(buff, sizeof(buff));
	    line = buff;
	    
	    if(infile.eof()) break;

	    if(line.find("From:") != -1) {
		if(line.find("\"") == 6) {		
		    CTokenizer tokens(line, "\"");
		    int n_tok = tokens.get_size();
		    value = new string(tokens.get_at(2).c_str());		    		
		    headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);		
		    if(n_tok > 1) {
			CTokenizer tokens(line, " ");
			n_tok = tokens.get_size();
			value = new string(tokens.get_at(n_tok). c_str());
			headers[EMAIL] = CPair(ID_HEADER_EMAIL, value);
		    }
		} else if(line.find("(") != -1) {
		    line = line.substr(6);
		    int ocorrencia = line.find('(');
		    string str = line.substr(ocorrencia);
		    str = str.substr(1, str.length() - 2);
		    value = new string(str);
		    headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);

		    str = "<" + line.substr(0, ocorrencia - 1) + ">";
		    value = new string(str);
		    headers[EMAIL] = CPair(ID_HEADER_EMAIL, value);
		} else {
		    if(line.find('<') != -1) {
			line = line.substr(6);
			int ocorrencia = line.find('<');
			string str = line.substr(0, ocorrencia - 1);
			value = new string(str);

			headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
			str = line.substr(ocorrencia);
			value = new string(str);
			headers[EMAIL] = CPair(ID_HEADER_EMAIL, value);
		    } else {
			value = new string(line.substr(6));
			headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
			headers[EMAIL] = CPair(ID_HEADER_EMAIL, new string("NULL"));
		    }
		}
	    } else if(line.find("Newsgroups:") != -1) {
		value = new string(line.substr(12));							
		headers[GROUPS] = CPair(ID_HEADER_GROUPS, value);					
	    } else if(line.find("X-Trace:") != -1) {
		line = line.substr(9);
		CTokenizer tokens(line, " ");
		string *ip = new string(tokens.get_at(4).c_str());
		hour = new string(tokens.get_at(tokens.get_size() - 1).c_str());

		headers[HOUR] = CPair(ID_HEADER_HOUR, hour);
		headers[IP] = CPair(ID_HEADER_IP, ip);
	    } else if(line.find("Subject:") != -1) {
		value = new string(line.substr(9));
		headers[SUBJECT] = CPair(ID_HEADER_SUBJECT, value);
	    } else if(line.find("X-Newsreader:") != -1) {
		line = line.substr(14);
		if(line.find("Microsoft") != -1)
		    xreader = new string(line.substr(0, 29));
		else if(line.find("Mozilla") != -1)
		    xreader = new string(line.substr(0, 11));
		else if(line.find("Forte Agent") != -1)
		    xreader = new string(line.substr(0, 16));
		else if(line.find("MICE BeOS") != -1)
		    xreader = new string(line.substr(0, 25));
		else if(line.find("Sylpheed") != -1)
		    xreader = new string(line.substr(0, 20));
		else
		    xreader = new string(line);
		headers[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, xreader);
	    } else if(line.find("User-Agent:") != -1) {
		line = line.substr(12);
		if(line.find("Mozilla") != -1)
		    xreader = new string(line.substr(0, 11));
		else if(line.find("Gnus") != -1)
		    xreader = new string(line.substr(0, 8));
		else if(line.find("Opera") != -1)
		    xreader = new string(line.substr(0, 9));
		else if(line.find("Pan") != -1)
		    xreader = new string(line.substr(0, 8));
		else if(line.find("newsSync") != -1)
		    xreader = new string(line.substr(0, 21));
		else
		    xreader = new string(line);
		headers[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, xreader);
	    } else if(line.find("Message-ID:") != -1) {
		value = new string(line.substr(12));
		headers[MSGID] = CPair(ID_HEADER_MSGID, value);
	    } else if(line.find("References:") != -1) {
		ref = true;
	    }
	}//while 1..
		
//		cout << "antes..." << endl;
		
		if(infile.eof()) break;
		bool repeteco = false;
		string grupo = *headers[GROUPS].get_value();
		
//		cout << "headers[GROUPS] = " << grupo << endl;
		
		if(grupo.find(",") != -1) {
			string hora  = *headers[HOUR].get_value();
			string both = grupo + " " + hora;
			vtStr::iterator itstr;
			for(itstr = verify_repeated.begin(); itstr != verify_repeated.end(); itstr++) {
			    string str = *itstr;
			    if(both == str) {
				repeteco = true;
				break;
			    }
			}
			/*for(unsigned int i = 0; i < verify_repeated.size(); i++) {
				string str = verify_repeated.at(i);
				if(both == str) {
					repeteco = true;
					break;
				}//if
			}//for
			*/
			if(verify_repeated.size() == 0)
				verify_repeated.push_back(both);
			if(!repeteco) {
				verify_repeated.push_back(both);
				cross = new string(grupo);
			} else {
				delete []headers;
				headers = 0;
				continue;
			}//else
		}
		if(xreader == NULL) {
			xreader = new string("indefinido");
			headers[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, xreader);
		}
		if(cross != NULL) {
			CTokenizer tokens(*cross, ",");
			*cross = "\n        " + *cross;
			int n_tok = tokens.get_size();
			for(int i = 1; i <= n_tok; i++) {
				string s = tokens.get_at(i).c_str();
				//*cross += "                    " + s + ",\n";
				CPair *hdrs = new CPair[8];
				hdrs[NICKNAME] = CPair(ID_HEADER_NICKNAME, new string(*headers[NICKNAME].get_value()));
				hdrs[EMAIL]   = CPair(ID_HEADER_EMAIL, new string(*headers[EMAIL].get_value()));
				hdrs[GROUPS] = CPair(ID_HEADER_GROUPS, new string(s));
				hdrs[HOUR]  = CPair(ID_HEADER_HOUR, new string(*headers[HOUR].get_value()));
				hdrs[IP]    = CPair(ID_HEADER_IP, new string(*headers[IP].get_value()));
				hdrs[SUBJECT] = CPair(ID_HEADER_SUBJECT, new string(*headers[SUBJECT].get_value()));
				hdrs[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, new string(*headers[NEWSREADER].get_value()));
				hdrs[MSGID]     = CPair(ID_HEADER_MSGID, new string(*headers[MSGID].get_value()));
				vArticlesGeral->push_back(new CArticle(hdrs, ref, ""));
			}
			vCross->push_back(new CPairInt(cross));
			delete []headers;
			headers = 0;
		} else
		vArticlesGeral->push_back(new CArticle(headers, ref, "hehe"));
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
		string from  = (*msg)->get_header(ID_HEADER_NICKNAME);
        string sender = (*msg)->get_header(ID_HEADER_EMAIL);
        string ngs     = (*msg)->get_header(ID_HEADER_GROUPS);
        string subject = (*msg)->get_header(ID_HEADER_SUBJECT);
        string reader  = (*msg)->get_header(ID_HEADER_NEWSREADER);
        string hour   = (*msg)->get_header(ID_HEADER_HOUR);
        string ip    = (*msg)->get_header(ID_HEADER_IP);

		vNickname->push_back(new CPairInt(new string(from)));
		vNickIp->push_back(new CPairInt(new string(from + " - (" + ip + ")")));
		vNickEmail->push_back(new CPairInt(new string(from + " - " + sender)));
		vNickEmailNg->push_back(new CPairInt(new string(from + " - " + sender + " - " + ngs)));
		vGroups->push_back(new CPairInt(new string(ngs)));
		vSubject->push_back(new CPairInt(new string(subject)));
		vSubjectNg->push_back(new CPairInt(new string(subject + " - " + ngs)));
		vHour->push_back(new CPairInt(new string(hour)));
		vXreader->push_back(new CPairInt(new string(reader)));
		vIp->push_back(new CPairInt(new string(ip)));

		if((*msg)->is_thread())
			m_totalReplys++;
	}//for
};//preenche

void CStatistics::put_together(vtPairInt *orig) {
    vtPairInt *vpi = new vtPairInt();
    for(it = orig->begin(); it != orig->end(); it++) {
	string s = *(*it)->get_value();
	bool contem = false;
	vtPairInt::iterator it2;
	for(it2 = vpi->begin(); it2 != vpi->end(); it2++) {
	    string s2 = *(*it2)->get_value();
	    if(s == s2) {
		contem = true;
		break;
	    }
	}//for
	if(contem)
	    (*it2)->increment_counter();
	else
	    vpi->push_back(new CPairInt(new string(*(*it)->get_value())));
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
	int out = 0;
//	put_together(vCross);
	for(it = vCross->begin(); it != vCross->end(); it++) {
  		string s = *(*it)->get_value();
  		//if(s.Find(",") != -1) {
			out  += (*it)->get_counter();
		//	CPairInt *pi2 = new CPairInt(new CString(s.Left(pos) + ",\n                    " +
		//		s.Right(pos2)), (*it)->get_counter());
		//	vCross->push_back(pi2);
		//}
	}
	m_totalX_Groups = vCross->size();
	return out;
};

string CStatistics::modelo1(const int &quantity)
{
    char buff[100];
    string out("");

    int pos = m_selected_ng.find_last_of(".");
    string ng = m_selected_ng.substr(pos + 1);

    m_subject = "## Estatísticas " + m_period;

    if(!m_selection)
	out += m_subject + " news.abusar (geral) ##\n";
    else
	out += m_subject + " " + ng + " ##\n";

    m_subject = out;

    sprintf(buff, "=Total de msgs:  %i (novas + repleiadas)\n", m_totalMsgs);
    out += buff;

    sprintf(buff, "=So as Novas  :  %i\n", m_totalNovos);
    out += buff;

    sprintf(buff, "=So os threads:  %i\n", m_totalReplys);
    out += buff;

    if(!m_selection) {
	sprintf(buff, "=Total de msgs cruzadas: %i\n", m_totalX_Msgs);
	out += buff;
    }

    sprintf(buff, "=Total de grupos: %i\n \n", m_totalGroups);
    out += buff;

    if(m_selection) {
	sprintf(buff, "*****Os %i maiores postadores do %s*****\n \n", quantity, ng.c_str());
	out += buff;
    } else {
	sprintf(buff, "*****Os %i maiores postadores da net*****\n \n", quantity);
	out += buff;
    }

    if(m_mode == ID_HEADER_NICKNAME)
	out += top_happen(quantity, ID_HEADER_NICKNAME);
    else if(m_mode == ID_HEADER_NICK_E_EMAIL)
	out += top_happen(quantity, ID_HEADER_NICK_E_EMAIL);
    else if(m_mode == ID_HEADER_NICK_E_IP)
	out += top_happen(quantity, ID_HEADER_NICK_E_IP);

    if(!m_selection) {
	sprintf(buff, " \n****Os 40 grupos mais badalados(%i total)****\n \n", m_totalNews);
	out += buff + top_happen(40, ID_HEADER_GROUPS);
	sprintf(buff," \n****Os %i grupos Cruzados mais postados(%i total)****\n \n", quantity, m_totalX_Groups);
	out += buff + top_happen(quantity, ID_HEADER_CROSS_GROUPS);
    }
	sprintf(buff, " \n***Os %i maiores threads(%i total)\n \n", quantity, m_totalReplys);
	out += buff + top_happen(quantity, ID_HEADER_SUBJECT_E_GROUP);

	sprintf(buff, " \n***Os \"Newsreaders\" mais usados..(em %%) (total - %i)\n \n", m_totalXreader);
    out += buff + top_happen(100, ID_HEADER_NEWSREADER);
    
	out += " \n";
    out += pico();

    if(m_dayly) {
	sprintf(buff,"\n**Primeira msg %s**\n\n", m_period.c_str());
	out += buff;
	out += postagem("primeira");
	sprintf(buff, "\n*Ultima msg %s*\n\n", m_period.c_str());
	out += buff;
	out += postagem("ultima");
    }

    if(m_dayly)
	sprintf(buff, " \n* Total de msgs do dia: %i *\n ", m_totalMsgs);
    else
	sprintf(buff, " \n* Total de msgs do período %s: %i *\n ", m_period.c_str(), m_totalMsgs);

    out += buff;

    if(!m_selection) {
	sprintf(buff, "# %i Usuarios (nicks iguais) ng.geral na data#\n ", m_totalNickname);
	out += buff;
	sprintf(buff, "# %i Usuarios (nicks iguais, email's diferentes) ng.geral na data#\n \n ", m_totalNickEmail);
        out += buff;
    }

    if(m_selection) {
	sprintf(buff, "%i Usuários (nicks iguais) ng.geral na data#\n", m_totalNickEmail);
        out += buff;
        if(m_dayly) {
	    sprintf(buff, "%i e ngs postados por eles na data#\n\n", m_totalNickname);
	    out += buff;
	    out += retorna_ngs_geral();
	}
    }
    out += "\n---X--- FIM ---X---\n";
    return out;
}
































