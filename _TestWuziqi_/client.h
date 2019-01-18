#pragma once
#include<cstdio>
#include<WinSock2.h>
#include"client_thread.h"

class Client
{
private:
	WSADATA c_WsaData;
	SOCKADDR_IN c_ClientAddr;
	int c_IsFail;
public:
	Client(WSADATA wsaData, SOCKET serverSocket);
	~Client();

	void RequestProtocol();
	void CreateSocket();
	void CreateSocketAddr();
	void LinkServer();

	inline int getIsFail() { return c_IsFail; };

};