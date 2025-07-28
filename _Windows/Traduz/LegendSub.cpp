// LegendSub.cpp: implementation of the CLegendSub class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Traduz.h"
#include "TraduzDlg.h"
#include "legendsub.h"
#include <fstream>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLegendSub::~CLegendSub() {}

void CLegendSub::nova(int sz) {
	for(int i = 0; i < sz; i++) {
		m_time->push_back(new CString("{}{}"));
		m_line->push_back(new CString("NULL\n"));
	}
}

void CLegendSub::complete_vetor(int sz) {
	for(int i = 0; i < sz; i++) {
		m_time->push_back(new CString("{}{}"));
		m_line->push_back(new CString("NULL\n"));
	}
}

void CLegendSub::open() {
	ifstream inFile;
	inFile.open(m_path);
	if(inFile.fail() == 1) {// 1 if not exists
		throw "Arquivo nao encontrado!\n";
	} else {
		//AfxMessageBox("inFile.open() successed!");
	    const int sz = 150;
	    char buf[sz];
	    while((inFile.eof() == 0)) {
		    inFile.getline(buf, 149); 
			CString linha = buf;
			if(linha == "") continue;
			if(linha.Find("NULL") == -1) {
			int last = 0;
			int index = 0;
			if(linha == "") break;
			TRACE(linha + "\n");
			for(int i = 0; buf[i] != 0; i++) {
				TRACE("%c", buf[i]);
				if(buf[i] == '}')
					last++;
				if(last == 2) {
					index = i;
					break;
				}
			}
		    m_time->push_back(new CString(linha.Left(index + 1)));			

			CString c = "";
			c = (linha.Right(linha.GetLength() - (index + 1))) + "\n";
		    m_line->push_back(new CString(c));
			}//if
			else {
				m_time->push_back(new CString("{}{}"));			
				m_line->push_back(new CString("NULL\n"));
			}
		}//while
	}
}

void CLegendSub::save() const
{
	ofstream outFile;
	outFile.open(m_path, ios::out);// | ios::app); //append
	if(!outFile) {
		AfxMessageBox("Arquivo nao pode ser salvo");
	}
	for(int i = 0; i < m_line->size(); i++)
	{
		CString *frame = (CString*)m_time->at(i);
		CString *fala  = (CString*)m_line->at(i);

		if(*fala != "NULL") {
			outFile.write(*frame, frame->GetLength());
			if(*fala == "")
				outFile.write("NULL\n", 5);
			else
				outFile.write(*fala,  fala->GetLength());
			//outFile.write("\n", 1);
		} else 
			outFile.write(*fala,  fala->GetLength());
	}
	outFile.close();
}
