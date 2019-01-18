#pragma once
#include<WinSock2.h>
#include"server_thread.h"
#pragma comment(lib,"Ws2_32.lib")

class Server
{
private:
	WSADATA s_WsaData;
	SOCKET s_ServerSocket;
	SOCKADDR_IN s_ServerAddr;

	int s_IsFail;//是否连接出错 0  -1
public:

	Server(WSADATA wsaData, SOCKET serverSocket);
	~Server();

	void RequestProtocol();
	void CreateSocket();
	void CreateSocketAddr();
	void Bind();
	void Listen();
	void ClientLink();
	inline int getClientCount() { return s_ClientCount; };
	inline int getIsFail() { return s_IsFail; };

};