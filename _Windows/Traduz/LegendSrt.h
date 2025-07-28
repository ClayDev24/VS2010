// LegendSrt.h: interface for the CLegendSrt class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEGENDSRT_H__48943F57_523E_48EF_86F8_63B5818A0AE9__INCLUDED_)
#define AFX_LEGENDSRT_H__48943F57_523E_48EF_86F8_63B5818A0AE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Legend.h"

class CLegendSrt : public CLegend  
{
public:

	CLegendSrt(const string &path) : CLegend(path) {};
	virtual ~CLegendSrt();
	virtual void save() const;
	virtual void open();
	virtual void nova(int sz);
	virtual void complete_vetor(int sz);
};

#endif // !defined(AFX_LEGENDSRT_H__48943F57_523E_48EF_86F8_63B5818A0AE9__INCLUDED_)
