/*
CLASS FOR SOCKET HANDLING WRITTEN IN 2003

YOU MUST LINK THE LIBRARY ws2_32.lib TO USE THIS CLASS

IF YOU HAVE ANY QUESTIONS EMAIL ME: fieseratte@gmx.de
*/

#include <winsock.h>
////////////////////////////////////////////////////////////////////////////////
#define SUCCESS 0
#define ERROR_CREATE 1
#define ERROR_BIND 2
#define ERROR_LISTEN 3
#define ERROR_CONNECT 4
#define ERROR_STARTWINSOCK 5
#define ERROR_ACCEPT 6
////////////////////////////////////////////////////////////////////////////////
int start_network()
{
WSADATA wsa;
long rc;
rc=WSAStartup(MAKEWORD(2,0),&wsa);
if(rc!=0)
   return ERROR_STARTWINSOCK;
else
   return SUCCESS;
}
////////////////////////////////////////////////////////////////////////////////
void finish_network()
{
WSACleanup();
}
////////////////////////////////////////////////////////////////////////////////
class network
{
private:
   char d[50];
   long rc;
   SOCKET s;
   SOCKADDR_IN addr;
   fd_set fds;
   timeval FAR wait;

public:
   int start()
   {
   wait.tv_sec=1;
   wait.tv_usec=0;
   s=socket(AF_INET, SOCK_STREAM, 0);
   if(s==INVALID_SOCKET)
      return ERROR_CREATE;
   else
      return SUCCESS;
   }

   int connect_to(int port, char ip[20])
   {
   memset(&addr, 0, sizeof(SOCKADDR_IN));
   addr.sin_family=AF_INET;
   addr.sin_port=htons(port);
   addr.sin_addr.s_addr=inet_addr(ip);
   rc=connect(s, (SOCKADDR*)&addr, sizeof(SOCKADDR));
   if(rc==SOCKET_ERROR)
      return ERROR_CONNECT;
   else
      return SUCCESS;
   }

   void send_data(char data[50])
   {
   send(s, data, 50, 0);
   }

   bool error_occured()
   {
   FD_ZERO(&fds);
   FD_SET(s, &fds);
   select(s, 0, 0, &fds, &wait);
   if(FD_ISSET(s, &fds))
      return true;
   else
      return false;
   }

   bool data_queued()
   {
   FD_ZERO(&fds);
   FD_SET(s, &fds);
   select(s, &fds, 0, 0, &wait);
   if(FD_ISSET(s, &fds))
      return true;
   else
      return false;
   }

   int accept_connection()
   {
   s=accept(s, NULL, NULL);
   if(s==INVALID_SOCKET)
      return ERROR_ACCEPT;
   else
      return SUCCESS;
   }

   int listen_for_connection(int port)
   {
   memset(&addr, 0, sizeof(SOCKADDR_IN));
   addr.sin_family=AF_INET;
   addr.sin_port=htons(port);
   addr.sin_addr.s_addr=INADDR_ANY;
   rc=bind(s,(SOCKADDR*)&addr,sizeof(SOCKADDR_IN));
   if(rc==SOCKET_ERROR)
      return ERROR_BIND;
   else
      {
      rc=listen(s, 10);
      if(rc==SOCKET_ERROR)
         return ERROR_LISTEN;
      else
         return SUCCESS;
      }
   }

   char *get_data()
   {
   recv(s, d, 50, 0);
   return d;
   }

   void finish()
   {
   closesocket(s);
   }

};
////////////////////////////////////////////////////////////////////////////////

