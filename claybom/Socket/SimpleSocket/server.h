#pragma once
#include "windows.h"
#include "winsock.h"
#include "stdio.h"

SOCKET sock;
SOCKADDR addr;
void MsgProc();

void simpleServer() {

	SOCKADDR_IN addr_in;
	addr_in.sin_family=AF_INET;
	addr_in.sin_port=100;
	addr_in.sin_addr.S_un.S_un_b.s_b1=127;
	addr_in.sin_addr.S_un.S_un_b.s_b2=0;
	addr_in.sin_addr.S_un.S_un_b.s_b3=0;
	addr_in.sin_addr.S_un.S_un_b.s_b4=1;

	memcpy(&addr,&addr_in,sizeof(SOCKADDR_IN));
	SOCKET temp=NULL;

	WSADATA dat;
	WORD ver=MAKEWORD(1,1);
	int res;

	printf("WSAStartup: %d Version %d\n",(res=WSAStartup(ver,&dat)),ver);

	if(res!=0)
		return;

	sock=socket(PF_INET,SOCK_STREAM,0);

	printf("Binding socket: %d\n",bind(sock,&addr,sizeof(addr)));
	printf("Listen mode: %d\n",listen(sock,5));

	while((temp=accept(sock,&addr,NULL))==SOCKET_ERROR);
	//sit & wait for a connection
	sock=temp;

	if(sock)
		MsgProc();
	WSACleanup();
}

void MsgProc() {
	char buf[100];
	int res=1;
	while((res=recv(sock,buf,100,0))!=SOCKET_ERROR) {
		if(res==0||res==WSAECONNRESET||res==WSAECONNABORTED) { //0==other side terminated conn
			printf("Client terminated connection\n");
			break;
		}
		_flushall(); //probably not needed
		printf("Recieved string: %s\n",buf);
		send(sock,buf,100,0);
	}
	closesocket(sock);
}