#include"server.h"
#include"server_thread.h"
#include<cstdio>
#pragma warning(disable:4996)

Server::Server(WSADATA wsaData, SOCKET serverSocket)
	:s_WsaData(wsaData), s_ServerSocket(serverSocket)
{
	s_ServerAddr = { 0 };
	s_IsFail = 0;
}

Server::~Server()
{
	closesocket(s_ServerSocket);//�رշ�����
	WSACleanup();//����ͷ�������ص���Ϣ
}

void Server::RequestProtocol()
{
	if (LOBYTE(s_WsaData.wVersion) != 2 || HIBYTE(s_WsaData.wVersion) != 2)
	{
		printf("step1(RequestProtocol)������汾ʧ�ܣ�\n");
		s_IsFail = -1;
	}
	else
	{
		printf("step1(RquestProtocol)������汾�ɹ���\n");
	}
}
void Server::CreateSocket()
{
	if (s_ServerSocket == -1)
	{
		printf("step2(CreateSocket)������Scoketʧ��!\n");
		s_IsFail = -1;
	}
	printf("step2(CreateSocket)������Scoket�ɹ�!\n");
}
void Server::CreateSocketAddr()
{
	s_ServerAddr.sin_family = AF_INET;
	s_ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	s_ServerAddr.sin_port = htons(9999);
	printf("step3(CreateSocketAddr)������server��ַ��Ϣ�ɹ���\n");
}
void Server::Bind()
{
	int bindState = bind(s_ServerSocket, (sockaddr*)&s_ServerAddr, sizeof(s_ServerAddr));
	if (bindState == -1)
	{
		printf("step4(Bind)����ʧ�ܣ�\n");
		s_IsFail = -1;
	}
	printf("step4(Bind)���󶨳ɹ���\n");
}
void Server::Listen()
{
	int listenNum = listen(s_ServerSocket, 20);
	if (listenNum == -1)
	{
		printf("step5(Listen)������ʧ�ܣ�\n");
		s_IsFail = -1;
	}
	printf("step5(Listen)�������ɹ���\n");
}
void Server::ClientLink()
{
	SOCKADDR_IN c_ClientAddr = { 0 };
	int len = sizeof(c_ClientAddr);
	int i = 0;
	while (i < 1024)
	{
		c_ClientSocket[i++] = accept(s_ServerSocket, (sockaddr*)&c_ClientAddr, &len);
		s_ClientCount++;
		if (c_ClientSocket[i - 1] == -1)
		{
			printf("step6(ClientLink):�ͻ�������ʧ�ܣ�\n");
			Server::~Server();
		}
		printf("step6(ClientLink):�ͻ������ӳɹ���\n");
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Commuciation, (LPVOID)i, NULL, NULL);
	}
}