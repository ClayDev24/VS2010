// NNTP.h: interface for the CNNTP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NNTP_H__A891B67F_5B32_43C4_819F_90A16FE63467__INCLUDED_)
#define AFX_NNTP_H__A891B67F_5B32_43C4_819F_90A16FE63467__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PairInt.h"
#include "Socket.h"
#include <fstream>
#include <vector>

typedef std::vector<CString> vtStr;

class CNNTP  
{
	CSocketClient *nntp;
	int totalMsgs;
	std::ofstream outFile;
	std::string data_vigente;
	std::string data_posterior;
	CString data_file;
	vetorStr  msgsIDs;
	void defineNewsQnt(MainFrame *pMain);
    vetorStr retornaIds(void);

  public:
	int QntMsgBaixadasPorPacote;
	int newsTotal;	
	std::string tempoDeDownload;				  
	//CNNTP() {};
    CNNTP(CString data_vig, CString data_post,CString file_name, int pct, std::string server, MainFrame* pMain);
	virtual ~CNNTP() {;};
	void gravar(const vetorStr &headers);	
    void run(void);
};

#endif // !defined(AFX_NNTP_H__A891B67F_5B32_43C4_819F_90A16FE63467__INCLUDED_)
