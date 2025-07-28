// LegendSrt.cpp: implementation of the CLegendSrt class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Traduz.h"
#include "TraduzDlg.h"
#include "LegendSrt.h"
#include <fstream>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLegendSrt::~CLegendSrt() {}

void CLegendSrt::nova(int sz) {
	for(int i = 0; i < sz; i++) {
		m_time->push_back(new CString(" --> "));
		m_line->push_back(new CString("NULL\n"));
	}
}

void CLegendSrt::complete_vetor(int sz) {
	for(int i = 0; i < sz; i++) {
		m_time->push_back(new CString(" --> "));
		m_line->push_back(new CString("NULL\n"));
	}
}

void CLegendSrt::open()
{
	ifstream inFile;
	inFile.open(m_path);
	if(inFile.fail() == 1) {// 1 if not exists
		throw "Arquivo nao encontrado!\n";
	} else {
		//AfxMessageBox("inFile.open() successed!");
	    const int sz = 250;
	    char buf[sz];
		CString linha = "";
		CString linha2 = "";

	    while((inFile.eof() == 0)) {
		    inFile.getline(buf, 199); 
			linha = buf;
			if(linha.Find("-->") != -1) {
				m_time->push_back(new CString(linha));
				linha2 = "";
				while(inFile.eof() == 0) {
					inFile.getline(buf, 199);
					linha = buf;
					if(linha != "") {
						linha2 += (linha + "\n");
					} else {
						m_line->push_back(new CString(linha2));
						break;
					}
				}
			}
		}//while
	}
}

void CLegendSrt::save() const
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
		//if(*fala != "NULL")
		//	outFile.write(*frame, frame->GetLength());
		char ch[10];		
		CString ln = itoa((i + 1), ch, 10);
		outFile.write(ln, ln.GetLength());
		outFile.write("\n", 1);
		outFile.write(*frame,  frame->GetLength());
		outFile.write("\n", 1);
		outFile.write(*fala, fala->GetLength());
		outFile.write("\n", 1);
		//if(*fala == "NULL")
		//	outFile.write("\n", 1);
	}
	outFile.close();
}
