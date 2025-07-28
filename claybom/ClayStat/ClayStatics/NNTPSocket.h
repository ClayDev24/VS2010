#pragma once
#include "socket++/sockinet.h"
#include <vector>
#include <string>
#include "Article.h"

typedef std::vector<std::string> vtStr;

class CNNTPSocket
{
public:
    CNNTPSocket(std::string server, int port = 119);
    virtual ~CNNTPSocket();
	std::string help();
	vtStr getList(void);
	vtStr getNewNews(std::string);
	vtStr getHead(std::string);
	vtStr getArticle(std::string id);
	vtStr getBody(std::string id);
	void  sendRequests(std::string);
	void  sendMessage(CArticle &msg);    
	vtStr getRequests(void);

private:
    std::string readFullyString(void);
    vtStr readFullyVector(void);
    std::string getCode();
    std::string resposta;
    iosockinet nntp;
};

class BadDate
{
        const char* const data;
    public:
        BadDate(const char* const msg = 0) : data (msg) {}
        std::string get_message() { return data; }
};


