#include"client.h"



Client::Client(WSADATA wsaData, SOCKET clientSocket)
	:c_WsaData(wsaData)
{
	c_ClientSocket = clientSocket;
	c_ClientAddr = { 0 };
	c_IsFail = 0;
}
Client::~Client()
{
	closesocket(c_ClientSocket);//关闭客户端
	WSACleanup();
}

void Client::RequestProtocol()
{
	if (LOBYTE(c_WsaData.wVersion) != 2 || HIBYTE(c_WsaData.wVersion) != 2)
	{
		printf("step1(RequestProtocol):请求版本失败！\n");
		c_IsFail = -1;
	}
	printf("step1(RequestProtocol):请求版本成功！\n");
}
void Client::CreateSocket()
{
	if (c_ClientSocket == -1)
	{
		printf("step2(CreateSocket):创建Socket失败！\n");
		c_IsFail = -1;
	}
	printf("step2(CreateSocket):创建Socket成功！\n");
}
void Client::CreateSocketAddr()
{
	c_ClientAddr.sin_family = AF_INET;
	c_ClientAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	c_ClientAddr.sin_port = htons(9999);
	printf("step3(CreateSocketAddr):绑定客户端成功！\n");
}
void Client::LinkServer()
{
	int linkState = connect(c_ClientSocket,(sockaddr*)&c_ClientAddr,sizeof(c_ClientAddr));
	if (linkState == -1)
	{
		printf("step4(LinkServer):连接服务器失败！\n");
	}
	printf("step4(LinkServer):连接服务器成功！\n");
	//通信
	CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)Recv_Show,NULL,NULL,NULL);
	char buffer[256];
	while (true)
	{
		memset(buffer, 0, sizeof(buffer));
		printf("请输入信息：");
		scanf("%s", buffer);
		int sendNum = send(c_ClientSocket, buffer, strlen(buffer), NULL);
		if (sendNum > 0)
		{
			printf("\n发送%d字节到服务器成功！\n", sendNum);
		}
	}



}
