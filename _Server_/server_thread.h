#pragma once
#include<cstdio>
#include<WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")

static int s_ClientCount;
static SOCKET c_ClientSocket[1024] = { 0 };

static LPTHREAD_START_ROUTINE Commuciation(LPVOID n)
{
	char buffer[256];
	int r;
	int i = (int)n;
	printf("��%dλ�û������ˣ�\n", i);
	while (true)
	{
		memset(buffer, 0, sizeof(buffer));
		//���տͻ��˷�������Ϣ
		r = recv(c_ClientSocket[i - 1], buffer, sizeof(buffer) - 1, NULL);
		if (r > 0)
		{
			printf("�û�%d->��%s\n", i, buffer);
			for (int j = 0; j < s_ClientCount; j++)
			{
				send(c_ClientSocket[j], buffer, sizeof(buffer), NULL);
			}
		}
	}
}