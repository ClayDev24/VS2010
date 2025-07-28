// Socket.h: interface for the CSocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOCKET_H__F2BD45C2_18EF_41C4_B3A5_D47CA3CECD2A__INCLUDED_)
#define AFX_SOCKET_H__F2BD45C2_18EF_41C4_B3A5_D47CA3CECD2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <WinSock2.h>
#include <vector>
#include "Article.h"
#include <iostream>

#pragma comment (lib, "Ws2_32.lib") 

typedef std::vector<CString> vetorStr;


class CSocket  
{
public:
    virtual ~CSocket();
	std::string ReceiveLine();
	std::string ReceiveBytes();
    void Close();
    void SendLine(std::string);
    void SendBytes(const std::string &s);
	std::string   help(void);
	vetorStr getList(void);
	vetorStr getNewNews(std::string, std::string);
	vetorStr getHead(std::string);
	vetorStr getArticle(std::string id);
	vetorStr getBody(std::string id);
	void     sendRequests(std::string);
	vetorStr getRequests(void);
	std::string readFullyString(void);
	vetorStr    readFullyVector(void);
	void sendMessage(CArticle &article);

  protected:
    CSocket();
    SOCKET s_;

  private:
    static void Start();
    static void End();
    static int  nofSockets_;
};

class CSocketClient : public CSocket {
  public:
	  CSocketClient(const std::string& host, int port);
};

class BadDate {
   const char* const data;
public:
   BadDate(const char* const msg = 0) : data (msg) {}
};

#endif // !defined(AFX_SOCKET_H__F2BD45C2_18EF_41C4_B3A5_D47CA3CECD2A__INCLUDED_)
