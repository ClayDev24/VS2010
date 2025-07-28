// CStatistics.cpp: implementation of the CCStatistics class.
#include "stdafx.h"
#include "ClayStat2.h"
#include "Statistics.h"
#include <iostream>

using namespace std;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
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

void CStatistics::change_vigent(UINT header) {
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
		//break;
	}
};

CString CStatistics::show(UINT header, CString kind) {
	change_vigent(header);
	if(kind == "name")
		sort(vVigent->begin(), vVigent->end(), NameCompare());
	else if(kind == "quantity")
		sort(vVigent->begin(), vVigent->end(), IntCompare());
	else
		return "NULL";
	CString out;
	out.Format("Total: %d\n", vVigent->size());
	bar = new CProgressBar();
	bar->Create(_T("Processando"), 80, vVigent->size());
	//bar->SetStep(10);
	if(kind == "quantity") {
		int cont = 0;
		for(it = vVigent->begin(); it != vVigent->end(); it++) {
			CString ordem;
			//case1:
			//ordem.Format("%i%c- %s%s\n", (i + 1), 186, percentage((*it)->get_counter()), (*it)->toString2());
			//out += ordem;			
			//case2:
			ordem.Format("%i%c- ", (++cont), 186);
			out += ordem + (*it)->toString() + "\n";
			bar->StepIt();
		}
	} else {
		for(it = vVigent->begin(); it != vVigent->end(); it++) {
			out += (*it)->toString() + "\n";
			bar->StepIt();
		}
	}
	bar->Clear();
	return out;
};

CString CStatistics::retorna_ngs_geral(void) {
	if(vNickname->size() == 0)
		return "Grupo inexistente ou digitado erroneamente...";
	CString out = "";

	sort(vNickname->begin(), vNickname->end(), NameCompare());
	vtPairInt::iterator it2;
	for(it2 = vNickname->begin(); it2 != vNickname->end(); it2++)
		out += pesquisa_pseudo(*(*it2)->get_value()) + "\n";  		
	return out;
};

CString CStatistics::pesquisa_pseudo(const CString &nick) {
	vtPairInt *ngs = retorna_ngs_inscritos(nick, ID_HEADER_NICKNAME);
	CString out = nick + ":\n:";
	for(it = ngs->begin(); it != ngs->end(); it++) {
		out += "          " + (*it)->toString() + "\n";
		delete *it;
	} 
	ngs->clear();
	delete ngs;
	return out;
};

CString CStatistics::advanced_search(const CString &nick, int header) {
	CString out = "Nenhuma ocorrência encontrada...\n";
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
		CString ng = *(*it)->get_value();
  		out += (*it)->toString() + ":\n";
  		int cont = 1;
		vtMsg::iterator itm;
  		for(itm = vArticlesGeral->begin(); itm != vArticlesGeral->end(); itm++) {		
			CString nick2 = (*itm)->get_header(header);
			if(nick == nick2) {
				CString ng2 = (*itm)->get_header(ID_HEADER_GROUPS);
				if(ng == ng2) {
				    CString str;
				    str.Format("%i - \n%s\n", cont++, (*itm)->toString2());
				    out += str;
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

vtPairInt* CStatistics::retorna_ngs_inscritos(const CString &nick, const int &hdr) {
	vtPairInt *vpi = new vtPairInt();
	vtMsg::iterator itm;
	for(itm = vArticlesGeral->begin(); itm != vArticlesGeral->end(); itm++) {
		CString nome2 = (*itm)->get_header(hdr);
		if(nick == nome2) {		  
			CPairInt *pi = new CPairInt(new CString((*itm)->get_header(ID_HEADER_GROUPS)));
			vpi->push_back(pi);
		}	  
	}
	put_together(vpi);
	return vpi;
};

CString CStatistics::postagem(const CString &s) {
	sort(vHour->begin(), vHour->end(), NameCompare());
	int index = 0;
	if(s == "primeira")
		it = vHour->begin();
	if(s == "ultima")
		it = vHour->end() - 1;
	CString hour = *(*it)->get_value();
	vtMsg::iterator msg;
	for(msg = vArticlesPartial->begin(); msg != vArticlesPartial->end(); msg++) {
		CString hour2 = (*msg)->get_header(ID_HEADER_HOUR);
		if(hour2 == hour) {
			return (*msg)->toString();
		}
	}
	return "NULL";
};
  	  	
vtStr CStatistics::top_happen_key(int qts, UINT header) {
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
	  
CString CStatistics::top_happen(int qts, UINT header) {
	change_vigent(header);
	CString out;
	sort(vVigent->begin(), vVigent->end(), IntCompare());
	vtPairInt::iterator fim;
	vtPairInt::iterator it2;
	vtPairInt::iterator it3;
    fim = vVigent->begin() + qts;
	if(fim > vVigent->end())
		fim = vVigent->end();
	int cont = 0;
	for(it2 = vVigent->begin(); it2 != fim; it2++) {
		CString ordem;
		ordem.Format("%i%c- %s%s\n", (++cont), 186, percentage((*it2)->get_counter()), (*it2)->toString2());
		out += ordem;
		if((header == ID_HEADER_NICKNAME) && m_view) {
			out += "     com os seguintes emails:\n";
			for(it3 = vNickEmail->begin(); it3 != vNickEmail->end(); it3++) {
				if((*(*it3)->get_value()).Find(*(*it2)->get_value()) != -1)
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

CString CStatistics::percentage(int i) {
	float source = ((i * 100.0) / vHour->size());
	CString out = "";
	out.Format("%*.*f%%", 5, 2, source);
	return out; 
};

//Horário de pico:
CString CStatistics::pico(void) {
	vtPairInt *vpi = new vtPairInt();
    CString out;
	for(it = vHour->begin(); it != vHour->end(); it++) {
		out = *(*it)->get_value();
		vpi->push_back(new CPairInt(new CString(out.Left(2))));
	}
	put_together(vpi);
	sort(vpi->begin(), vpi->end(), NameCompare());
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

void CStatistics::readFile(CString file_name) {	
	bar = new CProgressBar();
	bar->Create(_T("Processando"), 80, 180);
	bar->SetStep(10);

	vtMsg::iterator msg;
	for(msg = vArticlesGeral->begin(); msg != vArticlesGeral->end(); msg++)
		delete *msg;	
	vArticlesGeral->clear();

	vtPairInt::iterator itpi;
	for(itpi = vCross->begin(); itpi != vCross->end(); itpi++)
	    delete *itpi;
	vCross->clear();
	
	vtStr verify_repeated;	
	bar->StepIt();

    char buff[1024];
    ifstream infile(file_name);
    if (!infile)
		throw NoFile("O arquivo: \"" + file_name + "\" nao exite.\nTecle 'CTRL+D' para fazer o download...\n");
	vtStr ArquivoLinhas;
    while (!infile.getline(buff, sizeof(buff)).eof())
		ArquivoLinhas.push_back(buff);
//    infile.close();
//	CString line("");

	for(int iii = 0; iii < ArquivoLinhas.size(); iii++) {
	//while (!infile.getline(buff, sizeof(buff)).eof()) {
		CString line("");
//		if(infile.eof()) break;
//		line = buff;

		CPair *headers = new CPair[8];
		bool ref = false;
		CString *value;
		CString *xreader = NULL;
		CString *cross   = NULL;
		CString *hour    = NULL;

		while(line.Find("Xref:") == -1) {

			line = ArquivoLinhas.at(iii++);
		    line = line.Left(line.GetLength() - 1);
//			infile.getline(buff, sizeof(buff));
//			line = buff;
//			if(infile.eof()) break;

			if(line.Find(from_key) != -1) {
				if(line.Find("\"") == 6) {
					CTokenizer tokens((string)line, "\"");
					int n_tok = tokens.get_size();
					value = new CString(tokens.get_at(2).c_str());
					
					headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
					if(n_tok > 1) {
						CTokenizer tokens((string)line, " ");
						n_tok = tokens.get_size();
					    value = new CString(tokens.get_at(n_tok). c_str());
						headers[EMAIL] = CPair(ID_HEADER_EMAIL, value);
					}
				} else if(line.Find("(") != -1) {
					line = line.Mid(6);
					int ocorrencia = line.Find('(');
					CString str = line.Left(ocorrencia - 1);
					value = new CString(str);
					headers[EMAIL] = CPair(ID_HEADER_EMAIL, value);
					str = line.Mid(ocorrencia + 1, (line.GetLength() - (ocorrencia + 2)));					
					value = new CString(str);
					headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
				} else {
					if(line.Find('<') != -1) {					
					    //line = line.Right(line.GetLength() - 6);
						line = line.Mid(6);
					    int ocorrencia = line.Find('<');
					    CString str = line.Left(ocorrencia - 1);
					    value = new CString(str);
						headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
					    str = line.Mid(ocorrencia + 1, (line.GetLength() - (ocorrencia + 2)));					
					    value = new CString(str);
						headers[EMAIL] = CPair(ID_HEADER_EMAIL, value);
					} else {
						value = new CString(line = line.Right(line.GetLength() - 6));
						headers[NICKNAME] = CPair(ID_HEADER_NICKNAME, value);
						headers[EMAIL] = CPair(ID_HEADER_EMAIL, new CString("NULL"));
					}
				}
			} else if(line.Find(ngs_key) != -1) { 
				value = new CString(line.Mid(12));
				headers[GROUPS] = CPair(ID_HEADER_GROUPS, value);
			} else if(line.Find(xtrace_key) != -1) {				
				//line = line.Right(line.GetLength() - 9);				
				line = line.Mid(9);				
				CTokenizer tokens((string)line, " ");			    
			    CString *ip = new CString(tokens.get_at(4).c_str());			
			    hour = new CString(tokens.get_at(tokens.get_size() - 1).c_str());

				headers[HOUR] = CPair(ID_HEADER_HOUR, hour);
				headers[IP] = CPair(ID_HEADER_IP, ip);
			} else if(line.Find(subject_key) != -1) {
				value = new CString(line.Mid(9));//line.Right(line.GetLength() - 9));				
				headers[SUBJECT] = CPair(ID_HEADER_SUBJECT, value);
			} else if(line.Find(xreader_key) != -1) {
				//CString tmp = line.Right(line.GetLength() - 14);				
				line = line.Mid(14);
				if(line.Find("Microsoft") != -1)
					xreader = new CString(line.Left(29));
				else if(line.Find("Mozilla") != -1)
					xreader = new CString(line.Left(11));
				else if(line.Find("Forte Agent") != -1)
					xreader = new CString(line.Left(16));
				else if(line.Find("MICE BeOS") != -1)
					xreader = new CString(line.Left(25));
				else if(line.Find("Sylpheed") != -1)
					xreader = new CString(line.Left(20));
				else 
					xreader = new CString(line);
				headers[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, xreader);
			} else if(line.Find("User-Agent:") != -1) {
				//CString tmp = line.Right(line.GetLength() - 12);								
				line = line.Mid(12);
				if(line.Find("Mozilla") != -1)
					xreader = new CString(line.Left(11));
				else if(line.Find("Gnus") != -1)
					xreader = new CString(line.Left(8));
				else if(line.Find("Opera") != -1)
					xreader = new CString(line.Left(9));
				else if(line.Find("Pan") != -1)
					xreader = new CString(line.Left(8));
				else if(line.Find("newsSync") != -1)
					xreader = new CString(line.Left(21));
				else 
					xreader = new CString(line);				
				headers[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, xreader);
			} else if(line.Find(msgid_key) != -1) {	
				//value = new CString(line.Right(line.GetLength() - 12));
				value = new CString(line.Mid(12));
				headers[MSGID] = CPair(ID_HEADER_MSGID, value);
			} else if(line.Find(ref_key) != -1) {		
				ref = true;
			} 
		}//while 1..  	
//		if(infile.eof()) break;
		bool repeteco = false;	
		CString grupo = *headers[GROUPS].get_value();				
		if(grupo.Find(",") != -1) {
			CString hora  = *headers[HOUR].get_value();				
			CString both = grupo + " " + hora;
			for(int i = 0; i < verify_repeated.size(); i++) {
				CString str = verify_repeated.at(i);
				if(both == str) {
					repeteco = true;
					break;
				}//if
			}//for
			if(verify_repeated.size() == 0)
				verify_repeated.push_back(both);
			if(!repeteco) {
				verify_repeated.push_back(both);
				cross = new CString(grupo);
			} else {
				delete []headers;
				headers = 0;
				continue;
			}//else
		}
		if(xreader == NULL) {
			xreader = new CString("indefinido");
			headers[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, xreader);
		}
		if(cross != NULL) {
			CTokenizer tokens((string)*cross, ",");
			*cross = "\n        " + *cross;				  
			int n_tok = tokens.get_size();	
			for(int i = 1; i <= n_tok; i++) {
				CString s = tokens.get_at(i).c_str();					  
				//*cross += "                    " + s + ",\n";
				CPair *hdrs = new CPair[8];
				hdrs[NICKNAME] = CPair(ID_HEADER_NICKNAME, new CString(*headers[NICKNAME].get_value()));
				hdrs[EMAIL]   = CPair(ID_HEADER_EMAIL, new CString(*headers[EMAIL].get_value()));
				hdrs[GROUPS] = CPair(ID_HEADER_GROUPS, new CString(s));
			    hdrs[HOUR]  = CPair(ID_HEADER_HOUR, new CString(*headers[HOUR].get_value()));
				hdrs[IP]    = CPair(ID_HEADER_IP, new CString(*headers[IP].get_value()));
				hdrs[SUBJECT] = CPair(ID_HEADER_SUBJECT, new CString(*headers[SUBJECT].get_value()));
				hdrs[NEWSREADER] = CPair(ID_HEADER_NEWSREADER, new CString(*headers[NEWSREADER].get_value()));
				hdrs[MSGID]     = CPair(ID_HEADER_MSGID, new CString(*headers[MSGID].get_value()));
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
	bar->Clear();
	delete bar;
};

void CStatistics::define_partial(void) {
	bar->StepIt();
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
	bar->StepIt();
	preenche();
	bar->StepIt();						
	put_together(vNickname);	
	bar->StepIt();
	put_together(vSubject);	
	bar->StepIt();
	put_together(vGroups);	
	bar->StepIt();		
	put_together(vXreader);	
	bar->StepIt();									
	put_together(vSubjectNg);	
	bar->StepIt();									
	put_together(vNickEmail);	
	bar->StepIt();									
    put_together(vNickIp);	
	bar->StepIt();					
	put_together(vNickEmailNg);	
	bar->StepIt();					
	put_together(vIp);	
	bar->StepIt();					
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
		CString from  = (*msg)->get_header(ID_HEADER_NICKNAME);
        CString sender = (*msg)->get_header(ID_HEADER_EMAIL);
        CString ngs     = (*msg)->get_header(ID_HEADER_GROUPS);
        CString subject = (*msg)->get_header(ID_HEADER_SUBJECT);
        CString reader  = (*msg)->get_header(ID_HEADER_NEWSREADER);
        CString hour   = (*msg)->get_header(ID_HEADER_HOUR);
        CString ip    = (*msg)->get_header(ID_HEADER_IP);

		vNickname->push_back(new CPairInt(new CString(from)));
		vNickIp->push_back(new CPairInt(new CString(from + " - (" + ip + ")")));
		vNickEmail->push_back(new CPairInt(new CString(from + " - " + sender)));
		vNickEmailNg->push_back(new CPairInt(new CString(from + " - " + sender + " - " + ngs)));
		vGroups->push_back(new CPairInt(new CString(ngs)));				
		vSubject->push_back(new CPairInt(new CString(subject)));
		vSubjectNg->push_back(new CPairInt(new CString(subject + " - " + ngs)));
		vHour->push_back(new CPairInt(new CString(hour)));
		vXreader->push_back(new CPairInt(new CString(reader)));
		vIp->push_back(new CPairInt(new CString(ip)));
		
		if((*msg)->is_thread())
			m_totalReplys++;
	}//for
};//preenche

void CStatistics::put_together(vtPairInt *orig) {
	vtPairInt *vpi = new vtPairInt();
    for(it = orig->begin(); it != orig->end(); it++) {
		CString s = *(*it)->get_value();
		bool contem = false;
		vtPairInt::iterator it2;
		for(it2 = vpi->begin(); it2 != vpi->end(); it2++) {
			CString s2 = *(*it2)->get_value();
			if(s == s2) {
				contem = true;
				break;
			}
		}//for
		if(contem)
			(*it2)->increment_counter();
		else
			vpi->push_back(new CPairInt(new CString(*(*it)->get_value())));
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
  		CString s = *(*it)->get_value();
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

CString CStatistics::modelo1(const int &quantity)
{
	CString out = "";	
	CString str;
	int pos = m_selected_ng.ReverseFind('.');
	CString ng = m_selected_ng.Right(m_selected_ng.GetLength() - pos);
	m_subject = "## Estatísticas " + m_period;

    if(!m_selection)
		out += m_subject + " news.abusar (geral) ##\n";
	else
		out += m_subject + " " + ng + " ##\n";
	m_subject = out;

	str.Format("=Total de msgs:  %i (novas + repleiadas)\n", m_totalMsgs);
	out += str;
	str.Format("=So as Novas  :  %i\n", m_totalNovos);
	out += str;
	str.Format("=So os threads:  %i\n", m_totalReplys);
	out += str;

    if(!m_selection) {
		str.Format("=Total de msgs cruzadas: %i\n", m_totalX_Msgs);
		out += str;
	}      
	str.Format("=Total de grupos: %i\n \n", m_totalGroups);
    out += str;
    if(m_selection) {
		str.Format("*****Os %i maiores postadores do %s*****\n \n", quantity, ng);
		out += str;
	} else {
		str.Format("*****Os %i maiores postadores da net*****\n \n", quantity);
		out += str;
	}


    if(m_mode == ID_HEADER_NICKNAME) 
		out += top_happen(quantity, ID_HEADER_NICKNAME);
	else if(m_mode == ID_HEADER_NICK_E_EMAIL)
		out += top_happen(quantity, ID_HEADER_NICK_E_EMAIL);
    else if(m_mode == ID_HEADER_NICK_E_IP)
		out += top_happen(quantity, ID_HEADER_NICK_E_IP);

    if(!m_selection) {
		str.Format(" \n****Os 40 grupos mais badalados(%i total)****\n \n", m_totalNews);
		out += str + top_happen(40, ID_HEADER_GROUPS);
		str.Format(" \n****Os %i grupos Cruzados mais postados(%i total)****\n \n", quantity, m_totalX_Groups);
		out += str + top_happen(quantity, ID_HEADER_CROSS_GROUPS);
    }
	str.Format(" \n***Os %i maiores threads(%i total)\n \n", quantity, m_totalReplys);
	out += str + top_happen(quantity, ID_HEADER_SUBJECT_E_GROUP);

	str.Format(" \n***Os \"Newsreaders\" mais usados..(em %%) (total - %i)\n \n", m_totalXreader);
    out += str + top_happen(100, ID_HEADER_NEWSREADER);

	out += " \n";
    out += pico();

    if(m_dayly) {
		str.Format(" \n**Primeira msg %s**\n \n", m_period);
		out += str;
		out += postagem("primeira");				
		str.Format(" \n*Ultima msg %s*\n \n", m_period);
		out += str;
		out += postagem("ultima");		
    }
	if(m_dayly)
	    str.Format(" \n* Total de msgs do dia: %i *\n ", m_totalMsgs);
	else
		str.Format(" \n* Total de msgs do período %s: %i *\n ", m_period, m_totalMsgs);

    out += str;

    if(!m_selection) {
		str.Format("# %i Usuarios (nicks iguais) ng.geral na data#\n ", m_totalNickname);
		out += str;
		str.Format("# %i Usuarios (nicks iguais, email's diferentes) ng.geral na data#\n \n ", m_totalNickEmail);
        out += str;
    }     

    if(m_selection) {
		str.Format("%i na data#\n", m_totalNickEmail);
        out += str;
        if(m_dayly) {
			str.Format("%i e ngs postados por eles na data#\n\n", m_totalNickname);
			out += str;
			out += retorna_ngs_geral();
		}
    }
    out += "\n---X--- FIM ---X---\n";                 	                 
	return out;
}


