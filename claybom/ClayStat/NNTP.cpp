// NNTP.cpp: implementation of the CNNTP class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "ClayStat2.h"
#include "ClayStat2Doc.h"
#include "ClayStat2View.h"
#include "MainFrm.h"
#include "PairInt.h"
#include "Socket.h"
#include <vector>
#include <fstream>
#include "NNTP.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CNNTP::CNNTP(CString data_vig, CString data_post, CString file_name, int pct, string server, MainFrame* pMain) {
	totalMsgs   = 0;
	try{
  	nntp = new CSocketClient(server, 119);
	nntp->ReceiveLine();
	} catch(...) {
		TRACE("Conection's fallen...");
	}
	data_vigente   = data_vig;
	data_posterior = data_post;
	data_file      = file_name;
  	QntMsgBaixadasPorPacote = pct;
  	defineNewsQnt(pMain);
	try {
  	    run();
	} catch(char *s) {
		AfxMessageBox("Nenhuma mensagem nova...");
	}
}

void CNNTP::defineNewsQnt(MainFrame *pMain) {
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

void CNNTP::gravar(const vetorStr &headers) {
	for(int i = 0; i < headers.size(); i++)
		outFile << (string)headers.at(i) << endl;
	outFile << endl;
}
	
void CNNTP::run() {
	vetorStr headers;
	try {
		msgsIDs = retornaIds();
	} catch(BadDate &bd) {
		throw "no new messages...";
	}
	CString file  = (CString)".\\Message" + data_file + (CString)".txt";  	
	outFile.open(file, ios::out);// | ios::app); //append
	if(!outFile) {
		AfxMessageBox("Arquivo nao pode ser salvo");
	}
	char ch[10];
    TRACE("\nFazendo o download de : " + (CString)itoa(msgsIDs.size(), ch, 10) + (CString)" msgs...\n");

    for(int soma = 0; soma < msgsIDs.size();) {
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
				TRACE(itoa(contador, ch, 10) + (CString)"\n");       
			} catch(string error) {
				TRACE(error.c_str());
				TRACE("\nMsg nao disponivel...");
			} catch(...) {
				TRACE("Sem resposta...");	
			}
		}//while
	}//while2
	outFile.close();
	try {
		nntp->Close();
	} catch(...) {
		TRACE("Não consegui fechar a conexao...");
	}		
    TRACE("Total de msgs recebidas: " + (CString)itoa(totalMsgs, ch, 10));
}//run	
  	
vetorStr CNNTP::retornaIds() {
	vetorStr vt1;
	vetorStr vt2;
	try {
		vt1 = nntp->getNewNews("*", data_vigente + " 000000");//yy/mm/dd
	} catch(BadDate &bd) {
		TRACE("bd1");
		throw bd;
	}
	try {
		vt2 = nntp->getNewNews("*", data_posterior + " 000000");
	} catch(BadDate &bd) {
		TRACE("bd2");
		if(vt1.size() > 0)
			return vt1;
		else throw bd;
	}
	if(vt1.size() == 0) throw BadDate("No new messages");
	if(vt2.size() < 1) return vt1; 

	char ch[10];
	TRACE("vt1 = " + (CString)itoa(vt1.size(), ch, 10));
	TRACE("\nvt2 = " + (CString)itoa(vt2.size(), ch, 10));
	TRACE("\n");

	vtStr result;
	sort(vt2.begin(), vt2.end());
	for(int i = 0; i < vt1.size(); i++) {
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
	}
    TRACE("\nvt1 - vt2: " + (CString)itoa((vt1.size() - vt2.size()), ch, 10));    
    TRACE("\nresult:    " + (CString)itoa(result.size(), ch, 10));    
    return result;
}
