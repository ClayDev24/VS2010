// Legend.h: interface for the CLegend class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEGEND_H__5A4F9867_28BC_45BD_8FC5_D429C5676A84__INCLUDED_)
#define AFX_LEGEND_H__5A4F9867_28BC_45BD_8FC5_D429C5676A84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TraduzDlg.h"

typedef vector<CString*> vetorStr;

class CLegend  
{
public:
	CLegend(const string &path);
	virtual ~CLegend();
	virtual void open() {};
	virtual void save() const {};
	virtual void nova(int sz) {};
	virtual void complete_vetor(int sz) {};

	void set_line(CString line, int index) { *(CString*)m_line->at(index) = line; };
	void push_back(CString s) { m_line->push_back(new CString(s)); };

	void set_time(CString time, int index) { *(CString*)m_time->at(index) = time; };
	vetorStr* get_vetor()   { return m_line; };
	vetorStr* get_vetorTm() { return m_time; };
	CString   get_line(int index)  const { return *(CString*)m_line->at(index); };
	CString   get_time(int index) const { return *(CString*)m_time->at(index); };
	CString   get_next()        const;
	CString   get_previous()  const;
	CString   go(int index)  const;
	int      get_size()     const { return m_line->size(); };
	int      get_current()  const { return m_current; };

	vetorStr *m_line;
	vetorStr *m_time;

protected:
	const CString m_title;
	const CString m_path;
	mutable int   m_current;
};

#endif // !defined(AFX_LEGEND_H__5A4F9867_28BC_45BD_8FC5_D429C5676A84__INCLUDED_)
