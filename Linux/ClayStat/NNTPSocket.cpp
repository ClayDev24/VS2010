#include "NNTPSocket.h"

using namespace std;

/*
int main()
{
    CNNTPSocket client("news.abusar.org");
    CPair *headers = new CPair[8];
    headers[ID_HEADER_NICKNAME]   = CPair(ID_HEADER_NICKNAME, new string("claybom"));
    headers[ID_HEADER_EMAIL]      = CPair(ID_HEADER_EMAIL, new string("claybom@uol.com.br"));
    headers[ID_HEADER_GROUPS]     = CPair(ID_HEADER_GROUPS, new string("u-br.teste"));
    headers[ID_HEADER_SUBJECT]    = CPair(ID_HEADER_SUBJECT, new string("olá..."));
    headers[ID_HEADER_NEWSREADER] = CPair(ID_HEADER_NEWSREADER, new string("ClayStat =))"));
    
    string body("ola...");
    
    CArticle msg(headers, false, body);
    delete [] headers;
    cout << client.sendMessage(msg) << endl;	
    return 0;
}*/

CNNTPSocket::CNNTPSocket(string server, int port = 119) : resposta(""), nntp(sockbuf::sock_stream)
{
    char  buf[1024];
    nntp->connect(server.c_str(), "nntp", "tcp");
    nntp.getline(buf, 1024);
    cout << buf << endl;
}

CNNTPSocket::~CNNTPSocket() {
    char buf[1024];
    nntp << "QUIT\r\n" << flush;
    nntp.getline(buf, 1024);
    cout << buf << endl;
}

string CNNTPSocket::help() {
    nntp << "HELP\r\n" << flush;
    if(getCode() == "100")
    	return readFullyString();
    else
	throw resposta;
}

vtStr CNNTPSocket::getList(void) {
    nntp << "LIST\r\n" << flush;
    if(getCode() == "215")
        return readFullyVector();
    else
	throw resposta;
}

vtStr CNNTPSocket::getNewNews(string grupo_data) { // hms = yymmdd hhmmss
    string s = "NEWNEWS " + grupo_data + "\r\n";
    nntp << s << flush;
    string code = getCode();
    if(code == "230")
        return readFullyVector();
    else if(code == "501")
	throw BadDate(resposta.c_str());
    throw
	resposta;
}

vtStr CNNTPSocket::getHead(string id) {
    string s = "HEAD " + id + "\r\n";
    nntp << s << flush;    
    if(getCode() == "221") 
        return readFullyVector();
    else 
	throw resposta;
}

vtStr CNNTPSocket::getArticle(string id) {
    string s = "ARTICLE " + id + "\r\n";
    nntp << s << flush;
    if(getCode() == "220")
        return readFullyVector();
    else
	throw resposta;
}

vtStr CNNTPSocket::getBody(string id) {
    string s = "BODY " + id + "\r\n";
    nntp << s << flush;
    if(getCode() == "222")
        return readFullyVector();
    else
	throw resposta;

}

void CNNTPSocket::sendRequests(string id) {
    string s = "HEAD " + id + "\r\n";
    nntp << s << flush;
}

vtStr CNNTPSocket::getRequests(void) {
    if(getCode() == "221")
        return readFullyVector();
    else
	throw resposta;
}

string CNNTPSocket::readFullyString() {
    string out("");
    char buf[1024];
    while(nntp.getline(buf, 1024))  
	if(buf[0] == '.' && buf[1] == '\r')
	    break;
	else if(buf[0] == '.' && buf[1] == '.')	
	    out += (buf+1) + (string)"\n";
	else
	    out += buf + (string)"\n";
    return out;
}

vtStr CNNTPSocket::readFullyVector() {
    vtStr vtr;
    char buf[1024];
    string s;
    string s2;
    while(nntp.getline(buf, 1024))
    if(buf[0] == '.' && buf[1] == '\r')
	break;
    else if(buf[0] == '.' && buf[1] == '.') {
	s = buf;
	s2 = s.substr(0, s.length() - 1); // to take off '\n'
	vtr.push_back(s2);
    } else { 
	s = buf;
	s2 = s.substr(0, s.length() - 1); // to take off '\n'
	vtr.push_back(s2);
    }
    return vtr;
}

string CNNTPSocket::getCode()
{
    char buf[1024];
    nntp.getline(buf, 1024);
    resposta = buf;
    string code = resposta.substr(0, 3);
    return code;
}

void CNNTPSocket::sendMessage(CArticle &msg) {
    nntp << "POST\r\n" << flush;    
    string resp = getCode();
    cout << resposta << endl;
    if(resp == "340") {
	string id = resposta.substr(23);

	string nick = msg.get_header(ID_HEADER_NICKNAME);
	string email = msg.get_header(ID_HEADER_EMAIL);	
	string line = "From: " + nick + " " + email + "\r\n";
	nntp << line << flush;	
	cout << line;

	line = "Newsgroups: " + msg.get_header(ID_HEADER_GROUPS) + "\r\n";
	nntp << line << flush;
	cout << line;

	line = "Subject: " + msg.get_header(ID_HEADER_SUBJECT) + "\r\n";
	nntp << line << flush;
	cout << line;

	//line = "Date: " + msg.get_header(ID_HEADER_HOUR);
	//nntp << line << flush;

	line = "X-Newsreader: " + msg.get_header(ID_HEADER_NEWSREADER) + "\r\n";
	nntp << line << flush;
	cout << line;
	
	line = "Message-ID: " + id + "\n";
	nntp << line << flush;
	cout << line;

	nntp << "\r\n" << flush;
	
	string body = msg.get_body() + "\r\n";
	nntp << body << flush;
	cout << body;
	
	nntp << ".\r\n" << flush;
	
	char buff[1024];
	nntp.getline(buff, 1024);
	
	cout << buff << endl;
    } else if(resp == "440") {
	throw resposta;
    } else {
	throw resposta;
    }
}





