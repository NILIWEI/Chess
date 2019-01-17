
#include<cstdio>
#include<iostream>
#include<graphics.h>

#include"window.h"
#include"control.h"
#include"play.h"
#pragma warning(disable:4996)

int main()
{
	int state = 0;
	Control control;

	char title[20] = "五子棋大战";
	Window window(300, 300, 800, 600, title);
	window.drawWindow();

	HWND handle = GetHWnd();
	SetWindowText(handle, title);
	settextstyle(50, 20, "宋体");
	outtextxy(300, 300, "开始游戏");
	MOUSEMSG mouse;
	while (true)
	{

		mouse = GetMouseMsg();
		if (mouse.uMsg == WM_MOUSEMOVE && mouse.x >= 300 && mouse.y >= 300
			&& mouse.x <= 460 && mouse.y <= 350)
		{
			setlinecolor(RED);
			rectangle(300, 300, 460, 350);
			if (mouse.mkLButton)
			{
				state = 1;
				Sleep(300);
				cleardevice();
				break;
			}
		}
	}
	int gameState[BLOCK][BLOCK];
	memset(gameState, 0, sizeof(gameState));

	while (state)
	{
		control.startGame();

		window.drawChessBoard();
		SetWindowText(handle, title);
		Play play(gameState);
		play.dropChess();



	}

	control.endGame();



	system("pause");
	return 0;
}