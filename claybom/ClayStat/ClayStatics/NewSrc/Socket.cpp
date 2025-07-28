// Socket.cpp: implementation of the CSocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClayStat2.h"
#include "PairInt.h"
#include "Socket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int CSocket::nofSockets_= 0;

void CSocket::Start() {
  if(!nofSockets_) {
    WSADATA info;
    if(WSAStartup(MAKEWORD(2, 0), &info)) {
      throw "Could not start WSA";
    }
  }
  ++nofSockets_;
}

void CSocket::End() {
  WSACleanup();
}

CSocket::CSocket() : s_(0) {
  Start();
  // UDP: use SOCK_DGRAM instead of SOCK_STREAM
  s_ = socket(AF_INET, SOCK_STREAM, 0);
}

CSocket::~CSocket() {
  Close();
  --nofSockets_;
  if(!nofSockets_) End();
}

void CSocket::Close() {
  closesocket(s_);
}

string CSocket::help(void) {
	SendLine("HELP \r\n");
    return readFullyString();
}

vetorStr CSocket::getList(void) {
	SendLine("LIST \r\n");
	string resposta = ReceiveLine();
	TRACE("getList()... " + (CString)resposta.c_str());
	string code = resposta.substr(0, 3);
	CString resp = code.c_str();
	if(resp == "215") 
		return readFullyVector();
	else 
		throw resposta;
}

vetorStr CSocket::getNewNews(string grupos, string hms) { // hms = yymmdd hhmmss
	SendLine((string)("NEWNEWS " + (CString)grupos.c_str() + " " + (CString)hms.c_str() + "\r\n"));
	string resposta = ReceiveLine();
	TRACE("getNewNews()... " + (CString)resposta.c_str());
	string code = resposta.substr(0, 3);
	CString resp = code.c_str();
	if(resp == "230")
		return readFullyVector();
	else if(resp == "501")
		throw BadDate(resposta.c_str());
	throw BadDate(resposta.c_str());
}

vetorStr CSocket::getHead(string id) {
	SendLine(string((CString)"HEAD " + id.c_str() + "\r\n"));
	string resposta = ReceiveLine();
	TRACE("getHead()... " + (CString)resposta.c_str());
    string code = resposta.substr(0, 3);
	CString resp = code.c_str();
	if(resp == "221")
		return readFullyVector();
	else
		throw resposta;
}

vetorStr CSocket::getArticle(string id) {
	SendLine((string)((CString)"ARTICLE " + (CString)id.c_str() + "\r\n"));
	string resposta = ReceiveLine();
	TRACE("getArticle()... " + (CString)resposta.c_str());
    string code = resposta.substr(0, 3);
	CString resp = code.c_str();
	if(resp == "220")
		return readFullyVector();
	else
		throw resposta;
}

vetorStr CSocket::getBody(string id) {
	SendLine((string)((CString)"BODY " + (CString)id.c_str() + "\r\n"));
	string resposta = ReceiveLine();
	TRACE("getBody()... " + (CString)resposta.c_str());
    string code = resposta.substr(0, 3);
	CString resp = code.c_str();
	if(resp == "222")
		return readFullyVector();
	else
		throw resposta;
}

void CSocket::sendRequests(string id) {
	SendLine((string)((CString)"HEAD " + (CString)id.c_str() + "\r\n"));
}

vetorStr CSocket::getRequests(void) {
	string resposta = ReceiveLine();
    string code = resposta.substr(0, 3);
	CString resp = code.c_str();
	if(resp == "221")
		return readFullyVector();
	else
		throw resposta;
}     

string CSocket::readFullyString() {
	string str;
	while(1) {
		string linha = ReceiveLine();
		TRACE(linha.c_str());
		CString ln = linha.c_str();
		if (ln == ".\r\n") 
			return str;
		linha = linha.substr(0, linha.length() - 2); //to remove \r\n characters
		str += linha;
	}//while
}

vetorStr CSocket::readFullyVector() {
	vetorStr vtr;
	while(1) {
		string linha = ReceiveLine();
		//TRACE(linha.c_str());
		CString ln = linha.c_str();
		if(ln == ".\r\n")
			break;
		linha = linha.substr(0, linha.length() - 2); //to remove \r\n characters
		vtr.push_back(linha.c_str());
	}//while
	return vtr;
}

string CSocket::ReceiveBytes() {
	string ret;
	char buf[1024];
	int rv;
	while ((rv = recv(s_, buf, 1024, 0)) == WSAEMSGSIZE) {
		string t;
		t.assign(buf,1024);
		ret += t;
	}
	string t;
	t.assign(buf, rv);
	ret += t;
	return ret;
}

string CSocket::ReceiveLine() {
	string ret;
	while(1) {
		char r;
		switch(recv(s_, &r, 1, 0)) {
		case 0: // not connected anymore;
			return "";
		case -1:
			if(errno == EAGAIN)
				return ret;
			else				
				return "";// not connected anymore
		}
		ret += r;
		if(r == '\n')
			return ret;
	}//while
}
//{"From:", "Newsgroups:", "Subject:", "Date:", "X-Newsreader:"},
void CSocket::sendMessage(CArticle &msg) {
	SendLine("POST \r\n");
	string resposta = ReceiveLine();
	TRACE("sendMessage()... " + (CString)resposta.c_str());
    string code = resposta.substr(0, 3);
	CString resp = code.c_str();
	if(resp == "340") {
		string id = resposta.substr(23);

		string line = "From: " + msg.get_header(ID_HEADER_NICKNAME) + "\n";//vp->at(i)->toString() + "\n";
		TRACE(line.c_str());
		SendLine(line);
		
		line = "Newsgroups: " + msg.get_header(ID_HEADER_GROUPS) + "\n";
		TRACE(line.c_str());
		SendLine(line);
		
		line = "Subject: " + msg.get_header(ID_HEADER_SUBJECT) + "\n";
		TRACE(line.c_str());
		SendLine(line);
		
		line = "Date: " + msg.get_header(ID_HEADER_HOUR) + "\n";
		TRACE(line.c_str());
		SendLine(line);
		
		line = "X-Newsreader: " + msg.get_header(ID_HEADER_NEWSREADER) + "\n";
		TRACE(line.c_str());
		SendLine(line);
		
		//line = "Message-ID: " + id + "\n";
		line.append("Message-ID: ");
		line.append(id);
		line.append("\n");
		TRACE(line.c_str());
		SendLine(line);
		
		SendLine("\n");
		string body = msg.get_body();
		SendLine(body);
		SendLine(".\n");
		string s = ReceiveLine();
		TRACE(s.c_str());
	} else if(resp == "440") {
		throw resposta;
	} else {
		throw resposta;
	}	
}

void CSocket::SendLine(string s) {
	send(s_, s.c_str(), s.length(), 0);
}

void CSocket::SendBytes(const string& s) {
	send(s_, s.c_str(), s.length(), 0);
}

CSocketClient::CSocketClient(const string& host, int port) : CSocket() {
	string error;
	hostent *he;
	if ((he = gethostbyname(host.c_str())) == NULL) {
		error = strerror(errno);
		throw error;
	}
	sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((in_addr *)he->h_addr);
    memset(&(addr.sin_zero), 0, 8); 

    if (::connect(s_, (sockaddr *) &addr, sizeof(sockaddr))) {
		error = strerror(WSAGetLastError());
		throw error;
	}
}
