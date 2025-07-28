// Legend.cpp: implementation of the CLegend class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Traduz.h"
#include "TraduzDlg.h"
#include "Legend.h"
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLegend::CLegend(const string &path) : m_path(path.c_str()), m_current(0)
{
	m_line = new vetorStr();
	m_time = new vetorStr();
}

CLegend::~CLegend()
{
	for(int i = 0; i < m_line->size(); i++)
		delete((CString*)m_line->at(i));
	delete(m_line);
}

CString CLegend::get_next() const
{
	if(m_current < (get_size() - 1)) {
		++m_current;
		return *(CString*)m_line->at(m_current);
	}
	return *(CString*)m_line->at(get_size() - 1);
}

CString CLegend::get_previous() const
{
	if(m_current > 0) {
		--m_current;
		return *(CString*)m_line->at(m_current);
	}
	return *(CString*)m_line->at(0);
}

CString CLegend::go(int index) const
{
	if(index >= 0 && index < get_size()) {
		m_current = index;
		return *(CString*)m_line->at(m_current);
	} else AfxMessageBox("Indice Errado!");
	return "hehehe";
}