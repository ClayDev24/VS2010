#include "PairInt.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>
#include "NNTPSocket.h"
#include "ClientNNTP.h"

using namespace std;

/*int main()
{
    CClientNNTP cn("041020", "041021", "20oct", 500, "news.abusar.org");
    return 0;
}*/

extern char meses[][13];

CClientNNTP::CClientNNTP(sdate _date, string server) : 
    totalMsgs(0)
{
    char day[15];
    char month[15];
    char file[25];
    int d = _date.get_day();
    int m = _date.get_month();
    if(d < 10)
	sprintf(day, "0%i", d);
    else
	sprintf(day, "%i", d);
    if(m < 10)
	sprintf(month, "0%i", m);
    else
	sprintf(month, "%i", m);
    
    char vig[20];
    sprintf(vig, "%i%s%s", _date.get_year(), month, day);
    sprintf(file, "Message%i%s.txt", d, meses[m]);		
    _date++;
    
    d = _date.get_day();
    m = _date.get_month();
    if(d < 10)
	sprintf(day, "0%i", d);
    else
	sprintf(day, "%i", d);
    if(m < 10)
	sprintf(month, "0%i", m);
    else
	sprintf(month, "%i", m);
    
    char post[20];
    sprintf(post, "%i%s%s", _date.get_year(), month, day);
    
    outFile.open(file);

    nntp = new CNNTPSocket(server);
    data_vigente   = vig;
    data_posterior = post;
    try {
  	run();
    } catch(char *s) {
	cout << "Nenhuma mensagem nova..." << endl;
	outFile.close();
    }
}

/*void CClientNNTP::defineNewsQnt(MainFrame *pMain) {
	try {
		//MainFrame* pMain = (MainFrame*) ::AfxGetMainWnd();
	ClayStat2View *pView = (ClayStat2View*)pMain->GetActiveView();
	ClayStat2Doc *pDoc = (ClayStat2Doc*)pView->GetDocument();

		vetorStr lista;
		vetorStr lista2;
		ifstream inFile;
		inFile.open("list.txt");
		if(!inFile) {
			lista = nntp->getList();
			for(int i = 0; i < lista.size(); i++) {
				CString ng = (CString)lista.at(i);
				int pos = ng.Find(" ");
				ng = ng.Left(pos);
				pMain->m_wndDialogBar.m_combo.AddString(ng);
				lista2.push_back(ng);
			}
			outFile.open("list.txt", ios::out);// | ios::app); //append
			if(!outFile) {
				AfxMessageBox("Arquivo nao pode ser salvo");
			}
			gravar(lista2);
			outFile.close();
		} else {//0 exists:
			//char buf[150];
			//while((inFile.eof() == 0)) {
			//	inFile.getline(buf, 149); 
			//	CString ng = buf;
			//	if(ng != "" && ng != "\r")
			//		pMain->m_wndDialogBar.m_combo.AddString(ng);
			//}
		}
		pMain->m_wndDialogBar.m_combo.SetCurSel(0);		
		//ClayStat2Doc *pDoc = (ClayStat2Doc*)pMain->GetActiveDocument();
		//ASSERT_VALID(pDoc);
		pDoc->m_estat->m_totalGroups = lista.size();
	} catch(...) {
		TRACE("defineNewsQnt() ERROR!!!...\n");
	}
}//method
*/
void CClientNNTP::gravar(vtStr &headers) {
    vtStr::iterator it;
    for(it = headers.begin(); it != headers.end(); it++)
	outFile << (*it) << endl;
    outFile << endl;
}
	
void CClientNNTP::run() {
    vtStr headers;
    try {
	msgsIDs = retornaIds();
    } catch(BadDate &bd) {
	throw "no new messages...";
    }
    
    string file  = ".\\Message" + data_file + ".txt";
//    outFile.open(file.c_str(), ios::out);// | ios::app); //append
    if(!outFile) {
	cout << "Arquivo nao pode ser salvo" << endl;
    }
    
    cout << "Fazendo o download de : " << msgsIDs.size() << " msgs..." << endl;
    
/*
    for(unsigned int soma = 0; soma < msgsIDs.size();) {
	int contador = 0;
	for(; contador < QntMsgBaixadasPorPacote; contador++) {
	    if(soma < msgsIDs.size())
		nntp->sendRequests((string)msgsIDs.at(soma++));
			else
				break;
		}//for...
		while((contador--) > 0) {
			try {
				headers = nntp->getRequests();
				gravar(headers);
				totalMsgs++;
				char ch[10];
				//TRACE(itoa(contador, ch, 10) + (CString)"\n");
			} catch(string error) {
				//TRACE(error.c_str());
				;//TRACE("\nMsg nao disponivel...");
			} catch(...) {
				;//TRACE("Sem resposta...");
			}
		}//while
	}//while2
	outFile.close();
	try {
		delete nntp;//->Close();
	} catch(...) {
		;//TRACE("Não consegui fechar a conexao...");
	}*/
    
    vtStr::iterator it;
    for(it = msgsIDs.begin(); it != msgsIDs.end(); it++) {
        nntp->sendRequests(*it);
	cout << "enviando... " << *it << endl;
    }
    for(int i = 0; i < msgsIDs.size(); i++) {
    //for(it = msgsIDs.begin(); it != msgsIDs.end(); it++) {
	//string s = *it;
	//cout << "\"" << s << "\"" << endl;
	try {
	    headers = nntp->getRequests();
	    gravar(headers);
	    totalMsgs++;
	    cout << "recebendo msg " << (i + 1) << endl;
	} catch(string s) {
	    cout << s << endl;
	}
    }
    cout << "Total de msgs recebidas: " << totalMsgs << endl << endl;
    outFile.close();
}//run

vtStr CClientNNTP::retornaIds() {
    vtStr vt1;
    vtStr vt2;
    try {
	string s = "* " + data_vigente + " 000000";	
	vt1 = nntp->getNewNews(s); //yymmdd
    } catch(BadDate &bd) {
	throw bd;
    }
    try {
	string s = "* " + data_posterior + " 000000";
	vt2 = nntp->getNewNews(s);
    } catch(BadDate &bd) {
	if(vt1.size() > 0)
	    return vt1;
	else throw bd;
    }
    if(vt1.size() == 0)
	throw BadDate("No new messages");
    if(vt2.size() < 1)
        return vt1;

    cout << "vt1 = " << vt1.size() << endl;
    cout << "vt2 = " << vt2.size() << endl;

    vtStr result;
    /*sort(vt2.begin(), vt2.end());
    for(unsigned int i = 0; i < vt1.size(); i++) {
	int first = 0;
	int last  = vt2.size() - 1;
	bool foundFlag = false;
        while((first <= last) && (!foundFlag)) {
            int middle = (first + last) / 2;
		if(vt2.at(middle) == vt1.at(i))
		    foundFlag = true;
		else if(vt2.at(middle) > vt1.at(i))
		    last = middle - 1;
		else if(vt2.at(middle) < vt1.at(i))
		    first = middle + 1;
	}
        if(!foundFlag)
            result.push_back(vt1.at(i));
    }*/
    
    vtStr::iterator it1;
    vtStr::iterator it2;
    for(it1 = vt1.begin(); it1 != vt1.end(); it1++) {
	string s1 = *it1;
	bool found = false;
	for(it2 = vt2.begin(); it2 != vt2.end(); it2++) {
	    string s2 = *it2;
	    if(s1 == s2) {
		found = true;
		break;
	    }		
	}
	if(!found)
	    result.push_back(s1);
    }
    
    cout << "vt1 - vt2: " << vt1.size() - vt2.size()  << endl;
    cout << "result:    " << result.size() << endl;
    
    return result;
}



