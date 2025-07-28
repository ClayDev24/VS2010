// Article.h: interface for the CArticle class.
//
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_ARTICLE_H__19F16ED5_4295_4094_A576_4C6F6B31C48E__INCLUDED_)
#define AFX_ARTICLE_H__19F16ED5_4295_4094_A576_4C6F6B31C48E__INCLUDED_

#define NICKNAME   0
#define EMAIL      1
#define GROUPS     2
#define HOUR       3
#define IP         4
#define SUBJECT    5
#define NEWSREADER 6
#define MSGID      7

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
#include <vector>
#include "Pair.h"

const CString from_key    = "From:";
const CString sender_key  = "Sender:";
const CString ngs_key     = "Newsgroups:";
const CString xtrace_key  = "X-Trace:";
const CString subject_key = "Subject:";
const CString xreader_key = "X-Newsreader:";
const CString msgid_key   = "Message-ID:";
const CString ref_key     = "References:";
const CString hour_key    = "Hour:";
const CString ip_key      = "Ip:";

class CArticle {
	CPair *headers;
    CString body;
    bool    thread;

  public:
	CArticle() {};
	~CArticle();
	CArticle(CPair *headers, bool ref, CString body);
    CString toString(void) const;
    CString toString2(void) const;
	//inline functions:
    bool    is_thread(void) const { return thread;  }
    CString get_body(void)  const { return body;    }
    CString get_header(const int &hdr) const;
};
#endif // !defined(AFX_ARTICLE_H__19F16ED5_4295_4094_A576_4C6F6B31C48E__INCLUDED_)
