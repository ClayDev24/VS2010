// LegendSub.h: interface for the CLegendSub class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEGENDSUB_H__E3E2EA4D_1F82_49CD_AAE5_2ADC71DDEB1B__INCLUDED_)
#define AFX_LEGENDSUB_H__E3E2EA4D_1F82_49CD_AAE5_2ADC71DDEB1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Legend.h"

class CLegendSub : public CLegend  
{
public:
	CLegendSub(const string &path) : CLegend(path) {};
	virtual ~CLegendSub();
	virtual void save() const;
	virtual void open();
	virtual void nova(int sz);
	virtual void complete_vetor(int sz);

private:
//	vetorStr *m_frames;
};

#endif // !defined(AFX_LEGENDSUB_H__E3E2EA4D_1F82_49CD_AAE5_2ADC71DDEB1B__INCLUDED_)
