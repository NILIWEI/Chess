#pragma once
#include<cstdio>
#include<WinSock2.h>
#include<graphics.h>
#pragma comment(lib,"Ws2_32.lib")


static SOCKET c_ClientSocket;

static void Recv_Show()
{
	int i = 0;
	char buffer[256];
	int rec;
	while (true)
	{
		memset(buffer, 0, sizeof(buffer));
		rec = recv(c_ClientSocket, buffer, sizeof(buffer - 1), NULL);
		if (rec > 0)
		{
			settextcolor(YELLOW);
			settextstyle(18, 20, "ËÎÌו");
			outtextxy(0, i * 20, buffer);
			i++;
		}

	}

}