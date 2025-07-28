#include "include_all.h"
#include <cstdlib>
#include <cstdio>
#include <cctype> // isspace
#include <ctime> 

#include "Statistics2.h"
#include "..\..\include\utils.h"

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
	vVigent        = new vtPairInt();
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
//	vSubjectEng    = new vtPairInt();
};

CStatistics::~CStatistics() {
    DS_("~CStatistics()...")
    vtMsg::iterator itm;
    for(itm = vArticlesGeral->begin(); itm !=  vArticlesGeral->end(); itm++)
        delete *itm;
    vtPairInt::iterator it;
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
    for(it = vXreader->begin(); it !=  vXreader->end(); it++)
	delete *it;
    for(it = vNickIp->begin(); it != vNickIp->end(); it++)
	delete *it;
//    for(it = vSubjectEng->begin(); it != vSubjectEng->end(); it++)
//	delete *it;
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
//    delete vSubjectEng;
    delete vNickEmail;
    delete vNickEmailNg;
};

bool CStatistics::is_empty(void) {
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
//	case ID_HEADER_SUBJECT_E_GROUP:
//		vVigent = vSubjectEng;
//		break;
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

std::string CStatistics::show(HEADER header, std::string kind) {
    change_vigent(header);
    if(kind == "name")
        sort(vVigent->begin(), vVigent->end(), NameCompare);
    else if(kind == "quantity")
        sort(vVigent->begin(), vVigent->end(), IntCompare);
	
    std::string out;
	out = "Total: " + utils::_toStr(vVigent->size()) + "\n";
    vtPairInt::iterator it;
    if(kind == "quantity") {
        int i = 0;
	for(it = vVigent->begin(); it != vVigent->end(); it++) {
	    std::string ordem;
	    //case1:
	    //CPairInt *p = (CPairInt*)vVigent->at(i);
	    //ordem.Format("%i%c- %s%s\n", (i + 1), 186, percentage(p->get_counter()), p->toString2());
	    //out += ordem;
			
	    //case2:
	    ordem = utils::_toStr(++i) + char(186) + " ";
	    out += ordem + (*it)->toString() + "\n";
	}
    } else {
        for(it = vVigent->begin(); it != vVigent->end(); it++)
            out += (*it)->toString() + "\n";
    }
    return out;
};

std::string CStatistics::retorna_ngs_geral(void) {
    if(vNickname->size() == 0)
	return "Grupo inexistente ou digitado erroneamente...";
    std::string out = "";

    stable_sort(vNickname->begin(), vNickname->end(), NameCompare);
    vtPairInt::iterator it;
    for(it = vNickname->begin(); it != vNickname->end(); it++)
	out += pesquisa_pseudo(*(*it)->get_value()) + "\n";  		
    return out;
};

std::string CStatistics::pesquisa_pseudo(const std::string &nick) {
    vtPairInt *ngs = retorna_ngs_inscritos(nick, ID_HEADER_NICKNAME);
    std::string out = nick + ":\n:";
    vtPairInt::iterator it;
    for(it = ngs->begin(); it !=  ngs->end(); it++) {
	out += "          " + (*it)->toString() + "\n";
	delete *it;
    } 
    delete ngs;
    return out;
};

std::string CStatistics::advanced_search(const std::string &nick, const HEADER &header) {
    std::string out = "Nenhuma ocorrência encontrada...\n";
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
	CPairInt *pi = *it;
	std::string ng = *(*it)->get_value();
  	out += (*it)->toString() + ":\n";
  	int cont = 1;
	vtMsg::iterator it2;
  	for(it2 = vArticlesGeral->begin(); it2 != vArticlesGeral->end(); it2++) {
	    std::string nick2 = (*it2)->get_header(header);
  	    std::string ng2 = (*it2)->get_header(ID_HEADER_GROUPS);
	    if(nick == nick2 && ng == ng2)
		out += utils::_int2str(cont++) + " - \n" +  (*it2)->toString2() + "\n";
	}
	delete *it;
    }
    if(ngs->size() == 0) 
        return "Nenhuma ocorrência encontrada...\n";

    delete ngs;
    return out;
};

vtPairInt* CStatistics::retorna_ngs_inscritos(const std::string &nick, const HEADER &hdr) {
    vtPairInt *vpi = new vtPairInt();
    vtMsg::iterator it;
    for(it = vArticlesGeral->begin(); it != vArticlesGeral->end(); it++) {
	CArticle *msg = *it;
  	std::string name = msg->get_header(hdr);  		
	if(nick == name) {		  
	    std::string value = msg->get_header(ID_HEADER_GROUPS);
	    CPairInt *pi = new CPairInt(new std::string(value), 1);
	    vpi->push_back(pi);
	}	  
    }
    put_together(vpi);
    return vpi;
};

std::string CStatistics::postagem(const std::string &s) {
    sort(vHour->begin(), vHour->end(), NameCompare);
    vtPairInt::iterator it;
    if(s == "primeira")
        it = vHour->begin();
    if(s == "ultima")
	it = vHour->end() - 1;
    std::string hour = *(*it)->get_value();
    vtMsg::iterator itm;
    for(itm = vArticlesPartial->begin(); itm != vArticlesPartial->end(); itm++) {
	std::string hour2 = (*itm)->get_header(ID_HEADER_HOUR);
	if(hour2 == hour)
	    return (*itm)->toString();
    }
    return "NULL";
};
  	  	
vtStr CStatistics::top_happen_key(int qts, HEADER header) {
    change_vigent(header);
    sort(vVigent->begin(), vVigent->end(), IntCompare);
    vtStr vetor;
    vtPairInt::iterator it;
    vtPairInt::iterator index = vVigent->begin() + qts;
    if(index > vVigent->end())
    	index = vVigent->end();
    for(it = vVigent->begin(); it < index; it++)
	vetor.push_back((*it)->toString());		
    return vetor;
};
	  
std::string CStatistics::top_happen(int qts, HEADER header) {
    std::string out;
    change_vigent(header);
    sort(vVigent->begin(), vVigent->end(), IntCompare);
    vtPairInt::iterator it;
    vtPairInt::iterator index = vVigent->begin() + qts;
    if(index > vVigent->end())
        index = vVigent->end();
    int i = 0;
    for(it = vVigent->begin(); it < index; it++) {
	std::string ordem = utils::_toStr(++i) + char(186) + "- " +  percentage((*it)->get_counter()) + (*it)->toString2() + "\n";
	out += ordem;
	if(header == ID_HEADER_NICKNAME && m_view == true) {
 	    out += "     com os seguintes emails:\n";
	    vtPairInt::iterator it2;
	    for(it2 = vNickEmail->begin(); it2 != vNickEmail->end(); it2++)
		if((*(*it2)->get_value()).find(*(*it)->get_value()) != -1)
		    out += "     " + (*it2)->toString2() + "\n";				
	
	    out += "     e para os seguintes grupos:\n";
	    out += pesquisa_pseudo(*(*it)->get_value()) + "\n";
	}//if 
    }//for
    return out + "\n\n";
};

std::string CStatistics::percentage(int i) {
    float source = static_cast<float>(((i * 100.0) / vHour->size()));
    char ch[10];
    sprintf(ch, "%5.2f%%", source);
    std::string out = ch;
    return out; 
};

//Horário de pico:
std::string CStatistics::pico(void) {
    std::string out;
    vtPairInt *vpi = new vtPairInt();
    vtPairInt::iterator it;
    for(it = vHour->begin(); it != vHour->end(); it++) {
	out = *(*it)->get_value();
	vpi->push_back(new CPairInt(new std::string(out.substr(0, 2)), 1));
    }
    
    put_together(vpi);
    sort(vpi->begin(), vpi->end(), NameCompare);
    if(!m_selection)
	out = "***Horario de pico! (\"o\"=10 msgs):***\n\n";
    else 
	out = "***Horario de pico! (\"o\"=1 msg):***\n\n";
    for(it = vpi->begin(); it != vpi->end(); it++) {
	//CPairInt *p = (CPairInt*)vpi->at(i);
	int users = (*it)->get_counter();
	char user[15];
	sprintf(user, "%4d msgs - ", users);
	out += *(*it)->get_value() + "hs -" + user;
	if(!m_selection)
	    users = users / 10;
	for(int i2 = 0; i2 < users; i2++)
	    out += "o";
	out += "\n";	
	delete *it;
    }
    //for(i = 0; i < vpi->size(); i++)
    //    delete vpi->at(i);
    delete vpi;
    return out;
};
/*
void CStatistics::readFile(string file_name) {
    string line = "";
    vtPair *headers;
    
    cout << vArticlesGeral->size() << endl;
    if(vArticlesGeral->size() > 0) {
        vtMsg::iterator it;
            for(it = vArticlesGeral->begin(); it != vArticlesGeral->end(); it++)
                delete *it;
    }    
    vArticlesGeral->clear();//= new vtMsg();    

    ifstream file(file_name.c_str());

    if(!file) {
	string error = "O arquivo? \"" + file_name + "\"nao existe!.";
	throw NoFile(error.c_str());
    }
    vtStr verify_repeated;
    
    while(!file.eof()) {
	headers = new vtPair();
	string *value;
	string *xreader = NULL;
	bool ref = false;

	while(true) {
	    line = "";
	    char ch = ' ';
            while(!file.eof() && ch != '\n') {
	        file.get(ch);
		if(ch != '\r' && ch != '\n')
		    line += ch;
	    }
            if(file.eof())
		break;
		
	    int pos;
	    int sz;
	    string token[10];
	    if((pos = line.find("From:")) != -1) {	        
	        line += '\0';
	        string *email = NULL;
		if((pos = line.find("\"")) != -1) { 		    
		    sz = clb::split(line, '\"', token, 10);
		    value = new string(token[1]);
		    if(sz = 3)
		        email = new string(token[2].substr(1));
		} else if((pos = line.find("<")) != -1) {
		    sz = clb::split(line, ' ', token, 10);
		    if(sz > 2) {		
		        email = new string(token[sz - 1]);
			line = "";
			for(int i = 0; i < sz - 2; i++)
			    line += token[i + 1] + " ";
		        value = new string(line.substr(0, line.length() - 1));
		    } else
		        value = new string(token[1]);
		} else if(((pos = line.find("(")) != -1) && ((pos = line.find("@")) != -1)) {
		    sz = clb::split(line, ' ', token, 10);
		    email = new string(token[1]);
		    sz = clb::split(line, ' ', token, 10);
		    line = "";
		    for(int i = 0; i < sz - 2; i++)
		        line += token[i + 2] + " ";
		    value = new string(line.substr(0, line.length() - 1));
		} else {
		    value = new string(line.substr(6, line.length() - 7));
		}
		    headers->push_back(new CPair(ID_HEADER_NICKNAME, value));				
		    if(email != NULL)
		        headers->push_back(new CPair(ID_HEADER_EMAIL, email));		  
	    } else if((pos = line.find("Newsgroups:")) != -1) { 
		value = new string(line.substr(12));
		headers->push_back(new CPair(ID_HEADER_GROUPS, value));
	    } else if((pos = line.find("X-Trace:")) != -1) {
	        line += '\0';
		sz = clb::split(line, ' ', token, 10);
		string *ip = new string(token[4]);
		string *hour = new string(token[sz - 2]);
	
		headers->push_back(new CPair(ID_HEADER_HOUR, hour));
	        headers->push_back(new CPair(ID_HEADER_IP, ip));
	    } else if(line.find("Subject:") != -1) {
		value = new string(line.substr(9));
		headers->push_back(new CPair(ID_HEADER_SUBJECT, value));
	    } else if(line.find("X-Newsreader:") != -1) {
		line = line.substr(14);
		if(line.find("Microsoft") != -1)
		    xreader = new string(line.substr(0, 30));
		else if(line.find("Mozilla") != -1)
		    xreader = new string(line.substr(0, 13));
		else if(line.find("Forte Agent") != -1)
		    xreader = new string(line.substr(0, 18));
		else if(line.find("MICE BeOS") != -1)
		    xreader = new string(line.substr(0, 27));
		else if(line.find("Sylpheed") != -1)
		    xreader = new string(line.substr(0, 22));
		else 
		    xreader = new string(line);
		    
		headers->push_back(new CPair(ID_HEADER_NEWSREADER, xreader));			
	    } else if(line.find("User-Agent:") != -1) {
		line = line.substr(12);
		if(line.find("Mozilla") != -1)
		    xreader = new string(line.substr(0, 11));
		else if(line.find("Gnus") != -1)
		    xreader = new string(line.substr(0, 8));
		else if(line.find("Opera") != -1)
		    xreader = new string(line.substr(0, 9));
		else if(line.find("Pan") != -1)
		    xreader = new string(line.substr(0,8));
	        else 
		    xreader = new string(line);			
		
		headers->push_back(new CPair(ID_HEADER_NEWSREADER, xreader));  		
	    } else if(line.find("Message-ID:") != -1) {	
		value = new string(line.substr(12));
		headers->push_back(new CPair(ID_HEADER_MSGID, value));
	    } else if(line.find("References:") != -1) {
		//value = NULL;
		//headers->push_back(new CPair(ref_key, value));
		ref = true;
	    } else if(line.find("Xref:") != -1) {
		string ambos = "";
		bool repeteco  = false;
		bool eh        = false;
		vtPair::iterator it;
		for(it = headers->begin(); it != headers->end(); it++) {
		    CPair *par = *it;
		    if(par->get_key() == ID_HEADER_GROUPS) {
			if((*par->get_value()).find(",") != -1) {
			    ambos += *par->get_value() + " ";
			    eh = true;
			}
		    } else if((par->get_key() == ID_HEADER_HOUR) && eh) {
		        ambos += *par->get_value();
		        break;			
		    }
	        }//for
		if(eh) {
		    eh = false;
		    vtStr::iterator it;
		    if(verify_repeated.size() == 0) { 
		        verify_repeated.push_back(ambos);
		    }
		    for(it = verify_repeated.begin(); it != verify_repeated.end(); it++) {		        
		        string str = *it;
			if(ambos == str) {
			    repeteco = true;
		            break;
			}//if
		    }//for
		    if(!repeteco)
		        verify_repeated.push_back(ambos);
		    else {
		        vtPair::iterator pit;
		        for(pit = headers->begin(); pit !=  headers->end(); pit++)
			    delete *pit;
			headers->clear();
			continue;
		    }//else
		}//eh
		break;
	    }//else if			
          }//while 1..  		  
	  //jus' to add the las invalid header...
	  if(!file.eof()) {
	      if(xreader == NULL) {
	          xreader = new string("indefinido");
		  headers->push_back(new CPair(ID_HEADER_NEWSREADER, xreader));
	      }
	      vArticlesGeral->push_back(new CArticle(headers, ref, ""));
	  }
       }//while 2..       
       file.close();
       definePartial();	   
};
*/

void CStatistics::readFile(std::string file_name, std::string period) {
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
    std::ifstream infile(file_name.c_str());
    if (!infile) {
        std::string str("O arquivo ");
        str.append(file_name);
        str.append(" nao pode ser aberto!");
        const char *ch = str.c_str();
		throw NoFile(ch);
    }
	vtStr ArquivoLinhas;
    while (!infile.getline(buff, sizeof(buff)).eof())
		ArquivoLinhas.push_back(buff);
//    infile.close();
//	CString line("");

	for(unsigned int iii = 0; iii < ArquivoLinhas.size(); iii++) {
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
			line = ArquivoLinhas.at(iii++);
//			infile.getline(buff, sizeof(buff));
//			line = buff;
//			if(infile.eof()) break;

			if(line.find("From:") != -1) {
				if(line.find("\"") == 6) {
					clb::CTokenizer tokens(line, "\"");
					int n_tok = tokens.get_size();
					value = new std::string(tokens.get_at(2).c_str());
					headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
					if(n_tok > 1) {
						clb::CTokenizer tokens(line, " ");
						n_tok = tokens.get_size();
					    value = new std::string(tokens.get_at(n_tok). c_str());
						headers[EMAIL] = CPair(ID_HEADER_EMAIL, value);
					}
				} else if(line.find("(") != -1) {
					line = line.substr(6);
					int ocorrencia = line.find('(');
					std::string str = line.substr(ocorrencia);
					value = new std::string(str);
					headers[EMAIL] = CPair(ID_HEADER_EMAIL, value);

					str = "<" + line.substr(0, ocorrencia - 1) + ">";
					value = new std::string(str);
					headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
				} else {
					if(line.find('<') != -1) {
					    line = line.substr(6);
					    int ocorrencia = line.find('<');
					    std::string str = line.substr(0, ocorrencia - 1);
					    value = new std::string(str);

						headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
					    str = line.substr(ocorrencia);
					    value = new std::string(str);
						headers[EMAIL] = CPair(ID_HEADER_EMAIL, value);
					} else {
						value = new std::string(line.substr(6));
						headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
						headers[EMAIL] = CPair(ID_HEADER_EMAIL, new std::string("NULL"));
					}
				}
			} else if(line.find("Newsgroups:") != -1) {
				value = new std::string(line.substr(12));
				headers[GROUPS] = CPair(ID_HEADER_GROUPS, value);
			} else if(line.find("X-Trace:") != -1) {
				line = line.substr(9);

				clb::CTokenizer tokens(line, " ");
			    std::string *ip = new std::string(tokens.get_at(4).c_str());
			    hour = new std::string(tokens.get_at(tokens.get_size() - 1).c_str());

				headers[HOUR] = CPair(ID_HEADER_HOUR, hour);
				headers[IP] = CPair(ID_HEADER_IP, ip);
			} else if(line.find("Subject:") != -1) {
				value = new std::string(line.substr(9));
				headers[SUBJECT] = CPair(ID_HEADER_SUBJECT, value);
			} else if(line.find("X-Newsreader:") != -1) {
				line = line.substr(14);
				if(line.find("Microsoft") != -1)
					xreader = new std::string(line.substr(0, 29));
				else if(line.find("Mozilla") != -1)
					xreader = new std::string(line.substr(0, 11));
				else if(line.find("Forte Agent") != -1)
					xreader = new std::string(line.substr(0, 16));
				else if(line.find("MICE BeOS") != -1)
					xreader = new std::string(line.substr(0, 25));
				else if(line.find("Sylpheed") != -1)
					xreader = new std::string(line.substr(0, 20));
				else
					xreader = new std::string(line);
				headers[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, xreader);
			} else if(line.find("User-Agent:") != -1) {
				line = line.substr(12);
				if(line.find("Mozilla") != -1)
					xreader = new std::string(line.substr(0, 11));
				else if(line.find("Gnus") != -1)
					xreader = new std::string(line.substr(0, 8));
				else if(line.find("Opera") != -1)
					xreader = new std::string(line.substr(0, 9));
				else if(line.find("Pan") != -1)
					xreader = new std::string(line.substr(0, 8));
				else if(line.find("newsSync") != -1)
					xreader = new std::string(line.substr(0, 21));
				else
					xreader = new std::string(line);
				headers[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, xreader);
			} else if(line.find("Message-ID:") != -1) {
				value = new std::string(line.substr(12));
				headers[MSGID] = CPair(ID_HEADER_MSGID, value);
			} else if(line.find("References:") != -1) {
				ref = true;
			}
		}//while 1..
//		if(infile.eof()) break;
		bool repeteco = false;
		std::string grupo = *headers[GROUPS].get_value();
		if(grupo.find(",") != -1) {
			std::string hora  = *headers[HOUR].get_value();
			std::string both = grupo + " " + hora;
			for(unsigned int i = 0; i < verify_repeated.size(); i++) {
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
			clb::CTokenizer tokens(*cross, ",");
			*cross = "\n        " + *cross;
			int n_tok = tokens.get_size();
			for(int i = 1; i <= n_tok; i++) {
				std::string s = tokens.get_at(i).c_str();
				//*cross += "                    " + s + ",\n";
				CPair *hdrs = new CPair[8];
				hdrs[NICKNAME] = CPair(ID_HEADER_NICKNAME, new std::string(*headers[NICKNAME].get_value()));
				hdrs[EMAIL]   = CPair(ID_HEADER_EMAIL, new std::string(*headers[EMAIL].get_value()));
				hdrs[GROUPS] = CPair(ID_HEADER_GROUPS, new std::string(s));
			    hdrs[HOUR]   = CPair(ID_HEADER_HOUR,   new std::string(*headers[HOUR].get_value()));
				hdrs[IP]     = CPair(ID_HEADER_IP,     new std::string(*headers[IP].get_value()));
				hdrs[SUBJECT] = CPair(ID_HEADER_SUBJECT, new std::string(*headers[SUBJECT].get_value()));
				hdrs[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, new std::string(*headers[NEWSREADER].get_value()));
				hdrs[MSGID]     = CPair(ID_HEADER_MSGID, new std::string(*headers[MSGID].get_value()));
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
    vArticlesPartial = new vtMsg();
    if(m_selection) {
        vtMsg::iterator itm;
	for(itm = vArticlesGeral->begin(); itm != vArticlesGeral->end(); itm++) {
	    CArticle *msg = *itm;
	    std::string group = msg->get_header(ID_HEADER_GROUPS);
	    if(group == m_selected_ng)
	        vArticlesPartial->push_back(msg);
	}//for
    } else
	vArticlesPartial = vArticlesGeral;
    fill();	
};
	
void CStatistics::fill() {
    preenche();
					
    junta(vPseudo);
    junta(vSubject);	
    junta(vNews);							
    junta(vXreader);								
    junta(vSubjectEng);							
    junta(vPseudoEemail);						
    junta(vPseudoEip);			
    junta(vPseudoEemailEng);			
    junta(vIp);	
    
    define_quantity();
};
/*
void CStatistics::preenche() {
    cout << "preenche()..." << endl;
    vtPairInt::iterator it;
    if(!vIp->empty()) {
        vtPairInt::iterator it;
        for(it = vIp->begin(); it != vIp->end(); it++)
            delete *it;
    }
    if(!vHour->empty()) {
	for(it = vHour->begin(); it != vHour->end(); it++)
	    delete *it;
    }
    if(vNews->empty()) {
	for(it = vNews->begin(); it != vNews->end(); it++)
	    delete *it;
    }
    if(vCross->empty()) {
	for(it = vCross->begin(); it != vCross->end(); it++)
	    delete *it;
    }
    if(vPseudo->empty()) {
	for(it = vPseudo->begin(); it != vPseudo->end(); it++)
	    delete *it;
    }
    if(vSubject->empty()) {
	for(it = vSubject->begin(); it != vSubject->end(); it++)
	    delete *it;
    }
    if(vXreader->empty()) {
	for(it = vXreader->begin(); it != vXreader->end(); it++)
            delete *it;
    }
    if(vPseudoEip->empty()) {
	for(it = vPseudoEip->begin(); it != vPseudoEip->end(); it++)
	    delete *it;
    }
    if(vSubjectEng->empty()) {
	for(it = vSubjectEng->begin(); it != vSubjectEng->end(); it++)
	    delete *it;
    }
    if(vPseudoEemail->empty()) {
	for(it = vPseudoEemail->begin(); it != vPseudoEemail->end(); it++)
	    delete *it;
    }
    if(vPseudoEemailEng->empty()) {
	for(it = vPseudoEemailEng->begin(); it !=  vPseudoEemailEng->end(); it++)
	    delete *it;
    }
	
    vIp->clear();
    vHour->clear();
    vNews->clear();
    vCross->clear();
    vPseudo->clear();
    vSubject->clear();
    vXreader->clear();
    vPseudoEip->clear();
    vSubjectEng->clear();
    vPseudoEemail->clear();
    vPseudoEemailEng->clear();
    m_totalReplys = 0;

    vtPair *hdrs;
    CPair  *par;

    string from = "";
    string email = "";
    string ngs = "";
    string subject = "";
    string reader = "";
    string hour = "";
    string ip = "";
    vtMsg::iterator itm;
    for(itm = vArticlesPartial->begin(); itm !=  vArticlesPartial->end(); itm++) {
	CArticle *msg = *itm;
	hdrs = msg->get_headers();
	vtPair::iterator itp;
	for(itp = hdrs->begin(); itp !=  hdrs->end(); itp++) {
	    par = *itp;
	    if(par->get_key() == ID_HEADER_GROUPS) {
		ngs = *par->get_value();
	    } else if(par->get_key() == ID_HEADER_NICKNAME) {
		from = *par->get_value();
	    } else if(par->get_key() == ID_HEADER_EMAIL) {
		email = *par->get_value();
	    } else if(par->get_key() == ID_HEADER_SUBJECT) {
		subject = *par->get_value();
	    } else if(par->get_key() == ID_HEADER_NEWSREADER) {
		reader = *par->get_value();
	    } else if(par->get_key() == ID_HEADER_HOUR) {
		hour = *par->get_value();
	    } else if(par->get_key() == ID_HEADER_IP) {
		ip = *par->get_value();
	    } 
	}//for
	vPseudo->push_back(new CPairInt(new string(from), 1));
	vPseudoEip->push_back(new CPairInt(new string(from + " - (" + ip + ")"), 1));
	vPseudoEemail->push_back(new CPairInt(new string(from + " - " + email), 1));
	vPseudoEemailEng->push_back(new CPairInt(new string(from + " - " + email + " - " + ngs), 1));
	vNews->push_back(new CPairInt(new string(ngs), 1));				
	vSubject->push_back(new CPairInt(new string(subject), 1));
	vSubjectEng->push_back(new CPairInt(new string(subject + " - " + ngs), 1));
	vHour->push_back(new CPairInt(new string(hour), 1));
	vXreader->push_back(new CPairInt(new string(reader), 1));
	vIp->push_back(new CPairInt(new string(ip), 1));
		
	if(msg->is_thread())
	    m_totalReplys++;	
    }//for
}; //preenche
*/

void CStatistics::preenche() {
	using namespace std;
    vtPairInt::iterator it;
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
	using namespace std;
    vtPairInt *vpi = new vtPairInt();
    vtPairInt::iterator itpi;
    for(itpi = orig->begin(); itpi !=  orig->end(); itpi++) {
	string *s = (*itpi)->get_value();
	bool contem = false;	
	vtPairInt::iterator itpi2;
	for(itpi2 = vpi->begin(); itpi2 !=  vpi->end(); itpi2++) {
	    string *s2 = (*itpi2)->get_value();
	    if(*s == *s2) {
		contem = true;
		break;
	    }
	}//for
	if(contem)
	    (*itpi2)->increment_counter();
	else
	    vpi->push_back(new CPairInt(new string(*(*itpi)->get_value()), 1));
    }//for
    for(itpi = orig->begin(); itpi != orig->end(); itpi++)
        delete *itpi;
    orig[0] = vpi[0];//return vpi;
};

void CStatistics::define_quantity(void) {
    m_totalPseudoMaisEmail = vPseudoEemail->size();
    m_totalPseudo    =  vPseudo->size();
    m_totalNews      =    vNews->size();
    m_totalMsgs      =    vHour->size();
    m_totalXreader   = vXreader->size();
    m_totalNovos     = m_totalMsgs - m_totalReplys;  	
    m_totalCrossMsgs = retornaXPostingsTotal();
    m_totalIps       = vIp->size();
    m_totalSubject   = vSubject->size();
};

int CStatistics::retornaXPostingsTotal(void) {
	using namespace std;
    int out = 0;
    vtPairInt::iterator it;
    for(it = vNews->begin(); it != vNews->end(); it++) {
  	string s = *(*it)->get_value();
  	if(s.find(",") != -1) {
	    out += (*it)->get_counter();
	    string token[5];
	    s += '\0';
	    int sz = clb::split(s, ',', token, 5);
	    s.empty();
	    for(int i = 0; i < sz; i++) {
	        s += token[i] + '\n';
	    }
	    CPairInt *pi = new CPairInt(new string(s), (*it)->get_counter());
	    vCross->push_back(pi);
	}
    }
    m_totalCrossGroups = vCross->size();
    return out;
};

std::string CStatistics::modelo1(const int &quantity)
{
    std::string out = "";
    int pos = m_selected_ng.find_last_of(".");
    m_subject = "## Estatísticas " + m_period;

    if(!m_selection)
	out += m_subject + " news.abusar (geral) ##\n";
    else
	out += m_subject + " " + m_selected_ng.substr(pos) + " ##\n";
    m_subject = out;

    out += "=Total de msgs:  " + clb::int2str(m_totalMsgs) + " (novas + repleiadas)\n";
    out += "=So as Novas  :  " + clb::int2str(m_totalNovos) + "\n";
    out += "=So os threads:  " + clb::int2str(m_totalReplys) + "\n";

    if(!m_selection)
	out += "=Total de msgs cruzadas: " + clb::int2str(m_totalCrossMsgs) + "\n";
	
    out += "=Total de grupos: " + clb::int2str(m_totalGroups) + "\n\n";

    if(m_selection)
	out += "*****Os " + utils::_toStr(quantity) + " maiores postadores do " + m_selected_ng.substr(pos) + "*****\n\n";
    else
	out += "*****Os " + utils::_toStr(quantity) + " maiores postadores da net*****\n\n";

    if(m_mode == ID_HEADER_NICKNAME) 
	out += top_happen(quantity, ID_HEADER_NICKNAME);
    else if(m_mode == ID_HEADER_NICK_E_EMAIL)
	out += top_happen(quantity, ID_HEADER_NICK_E_EMAIL);
    else if(m_mode == ID_HEADER_NICK_E_IP)
	out += top_happen(quantity, ID_HEADER_NICK_E_IP);
	      
    if(!m_selection) {
	out += "****Os 40 grupos mais badalados(" + clb::int2str(m_totalNews) + " total, dos quais " + clb::int2str(m_totalCrossGroups) + " sao cruzados)****\n\n";
	out += top_happen(40, ID_HEADER_GROUPS);

	out += "****Os " + clb::int2str(quantity) + " grupos Cruzados mais postados(" + clb::int2str(m_totalCrossGroups) + " total)****\n\n";
	out += top_happen(quantity, ID_HEADER_CROSS_GROUPS);
    }

    out += "***Os " + clb::int2str(quantity) + " maiores threads(" + clb::int2str(m_totalReplys) + " total)\n\n";
    out += top_happen(quantity, ID_HEADER_SUBJECT_E_GROUP);

    out += "***Os \"Newsreaders\" mais usados..(em %) (total - " + clb::int2str(m_totalXreader) + ")\n\n";
    out += top_happen(100, ID_HEADER_NEWSREADER);
    
    out += pico();
        
//    if(m_dayly) {
//	out += "\n**Primeira msg " + m_period +  "**\n\n";
//	out += postagem("primeira");				
//	out += "\n*Ultima msg " + m_period + "*\n\n";
//	out += postagem("ultima");		
//    }
        
    out += "\n* Total de msgs do dia: " + clb::int2str(m_totalMsgs) + " *\n";

    if(!m_selection) {
	out += "# " + clb::int2str(m_totalPseudo) + " Usuarios (nicks iguais) ng.geral na data#\n";
	out += "# " + clb::int2str(m_totalPseudoMaisEmail) + " Usuarios (nicks iguais, email's diferentes) ng.geral na data#\n\n";
    }     

    if(m_selection) {
	out += clb::int2str(m_totalPseudoMaisEmail) + " na data#\n";
        if(m_dayly) {
	    out += m_totalPseudo + " e ngs postados por eles na data#\n\n";
	    out += retorna_ngs_geral();
	}
    }
    out += "\n---X--- FIM ---X---\n";                 	                 
    return out;
}





