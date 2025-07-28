// Statistics.h: interface for the CStatistics class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATISTICS_H__91C7E4C9_8FD3_4301_9C5E_27C11ADE296A__INCLUDED_)
#define AFX_STATISTICS_H__91C7E4C9_8FD3_4301_9C5E_27C11ADE296A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#include <string>
	#include <cctype> // isspace
	#include <ctime> 

#include "ProgressBar.h"
#include "Pairint.h"
#include "Tokenizer.h"
#include "Article.h"

#define operador LessThan

typedef std::vector<CString>   vtStr;
typedef std::vector<CArticle*> vtMsg;
typedef std::vector<CPairInt*> vtPairInt;
typedef std::vector<CPair*> vtPair;

class IntCompare:std::binary_function<CPairInt, CPairInt, bool> {
  public:
	bool operator() (CPairInt *a, CPairInt *b) {
	  return (a->operador(b));
	}
};

class NameCompare:std::binary_function<CPair, CPair, bool> {
  public:
	bool operator() (CPair *a, CPair *b) {
	  return (a->operador(b));
	}
};

class CStatistics : public CObject  
{
public:
	CStatistics();
	virtual ~CStatistics();
	CProgressBar *bar;
    int m_totalNickname;
    int m_totalNickEmail;
    int m_totalNews;
    int m_totalMsgs;
    int m_totalXreader;
    int m_totalNovos;
    int m_totalX_Msgs;
	int m_totalGroups;
    int m_totalX_Groups;
    int m_totalReplys;
    int m_totalIps;
    int m_totalSubject;

	CString m_selected_ng;
	CString m_subject;
	CString m_period;

	bool m_view;
	bool m_selection;
	bool m_dayly;
	int  m_mode;

    bool is_empty(void);
    CString show(UINT header, CString kind);
    CString retorna_ngs_geral(void);
    CString pesquisa_pseudo(const CString &nick);
	CString advanced_search(const CString &nick, int header);
    vtPairInt* retorna_ngs_inscritos(const CString &nick, const int &hdr);
	CString  postagem(const CString &s);  	  	
	vtStr    top_happen_key(int qts, UINT header);
	CString  top_happen(int qts, UINT header);
	CString  pico(void);
	void    readFile(CString file_name);
	void    define_partial(void);	
	CString modelo1(const int &quantity);

private:
	vtMsg *vArticlesGeral;
	vtMsg *vArticlesPartial;
	vtPairInt *vVigent;
  	vtPairInt *vIp;
  	vtPairInt *vHour;
  	vtPairInt *vGroups;
  	vtPairInt *vCross;
  	vtPairInt *vNickname;
  	vtPairInt *vSubject;
  	vtPairInt *vXreader;
  	vtPairInt *vNickIp;
  	vtPairInt *vNickEmail;
  	vtPairInt *vNickEmailNg;
  	vtPairInt *vNewsHora;
  	vtPairInt *vSubjectNg;
	vtPairInt::iterator it;

	void define_quantity(void);
	void change_vigent(UINT header);
	void fill(void);
	void preenche();
	int retornaXPostingsTotal(void);
	CString percentage(int i);
	void put_together(vtPairInt *orig);
};

class NoFile {
	const CString data;
public:
   NoFile(const char* const msg = 0) : data (msg) {}
   CString get_message(void) { return data; }
};

#endif // !defined(AFX_STATISTICS_H__91C7E4C9_8FD3_4301_9C5E_27C11ADE296A__INCLUDED_)
