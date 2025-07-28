// tnntp.cc
#include "sockinet.h"

int main ()
{
    char  buf[1024];
    iosockinet io (sockbuf::sock_stream);
    io->connect ("news.abusar.org", "nntp", "tcp");
    io.getline (buf, 1024); cout << buf << endl;
    io << "LIST\r\n" << flush;
    io.getline (buf, 1024); cout << buf << endl;
    while (io.getline (buf, 1024))
        if (buf[0] == '.' && buf[1] == '\r') break;
        else if (buf[0] == '.' && buf[1] == '.') cout << buf+1 << endl;
        else cout << buf << endl;
    io << "HELP\r\n"<< flush;
    while (io.getline (buf, 1024))
        if (buf[0] == '.' && buf[1] == '\r') break;
        else if (buf[0] == '.' && buf[1] == '.') cout << buf+1 << endl;
        else cout << buf << endl;
        
    io << "QUIT\r\n" << flush;
    io.getline (buf, 1024); cout << buf << endl;
    return 0;
}
