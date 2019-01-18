#include"server.h"
int main()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	Server server(wsaData, serverSocket);
	server.RequestProtocol();
	server.CreateSocket();
	server.CreateSocketAddr();
	server.Bind();
	server.Listen();
	server.ClientLink();
	if (server.getIsFail() < 0)
	{
		return -1;
	}
	return 0;
}