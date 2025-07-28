#pragma once
#include "windows.h"
#include "winsock.h"
#include "stdio.h"
#include "process.h"

void MsgProc(SOCKADDR addr, SOCKET sock=NULL);

void simpleClient() {
	SOCKET sock=NULL;
	SOCKADDR addr;

	WSADATA dat;
	WORD ver=MAKEWORD(1,1);

	int res;
	SOCKADDR_IN addr_in;
	addr_in.sin_family=AF_INET;
	addr_in.sin_port=100;
	addr_in.sin_addr.S_un.S_un_b.s_b1=127;
	addr_in.sin_addr.S_un.S_un_b.s_b2=0;
	addr_in.sin_addr.S_un.S_un_b.s_b3=0;
	addr_in.sin_addr.S_un.S_un_b.s_b4=1;

	memcpy(&addr,&addr_in,sizeof(SOCKADDR_IN));

	//auto-start server
	system("start .\\srvr.exe");
	printf("Remember, 0s are good\n");
	printf("WSAStartup: %d. Version %d\n",(res=WSAStartup(ver,&dat)),ver);

	if(res!=0)
		return;

	sock=socket(PF_INET,SOCK_STREAM,0);
	printf("Connect: %d\n",(res=connect(sock,&addr,sizeof(addr))));

	if(sock==NULL||res!=0)
		return;

	MsgProc(addr);
	WSACleanup();
}

void MsgProc(SOCKADDR addr, SOCKET sock) {
	char str[100]="";
	int res;

	while(stricmp(str,"exit")!=0){
		printf("String to send: ");
		gets(str);
		send(sock,str,100,0);

		for(int i=0;(res=recv(sock,str,100,0))==SOCKET_ERROR&&i<50;i++)
			Sleep(100);

		if(res==0||res==WSAECONNRESET||res==WSAECONNABORTED){//0==other side terminated conn
			printf("Server terminated connection\n");
			break;
		}
		printf("Recieved string: %s\n",str);
	}
	closesocket(sock);
}