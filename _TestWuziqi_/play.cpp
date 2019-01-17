#include"play.h"
#include"control.h"
#include<graphics.h>
#include<Windows.h>
#include"window.h"

Play::Play(int gameState[BLOCK][BLOCK])
{
	for (int i = 0; i < BLOCK; i++)
		for (int j = 0; j < BLOCK; j++)
			p_GameState[i][j] = gameState[i][j];
	p_StepNum = 0;
	p_Winner = 0;
}
Play::~Play()
{

}
void Play::initPlay()
{
	memset(p_GameState, 0, sizeof(p_GameState));
}

void Play::dropChess()
{

	while (checkIsEnd() == false)
	{
		if (p_StepNum == 5)
		{
			p_StepNum = 0;
			ifAgain();
		}

		MOUSEMSG mouse = GetMouseMsg();
		if (mouse.x < 16 || mouse.y < 16 || mouse.x>586 || mouse.y>586)
		{
		}
		else
		{
			int xCurPos = 0;
			int yCurPos = 0;
			if (mouse.x % 38 <= 16)
				xCurPos = (int)(mouse.x - mouse.x % 38);
			if (mouse.y % 38 <= 16)
				yCurPos = (int)(mouse.y - mouse.y % 38);

			if (mouse.x % 38 > 16)
				xCurPos = (int)(mouse.x + 38 - mouse.x % 38);
			if (mouse.y % 38 > 16)
				yCurPos = (int)(mouse.y + 38 - mouse.y % 38);
			int i = xCurPos / 38 - 1;
			int j = yCurPos / 38 - 1;
			if (mouse.uMsg == WM_LBUTTONDBLCLK)//双击落棋
			{
				if (!p_GameState[i][j])//没有走过棋子
				{
					addStepNum();//走一步，加一次计数
					int playerNum = (getStepNum() + 1) % 2 + 1;//1为先手，2为后手
					p_GameState[i][j] = playerNum;
#pragma region 测试矩阵的值
					/*for (int k = 0; k < 15; k++)
					{
						for (int m = 0; m < 15; m++)
						{
							outtextxy(570 + k * 10, 20 + m * 10, p_GameState[k][m]);
						}
					}
*/
#pragma endregion

					if (playerNum % 2 == 1)
					{
						setfillcolor(RED);
						fillcircle(xCurPos, yCurPos, 14);
					}
					else
					{
						setfillcolor(WHITE);
						fillcircle(xCurPos, yCurPos, 14);
					}

				}
				else
				{
					//这里已经走过棋子了
				}
			}


		}

	}
	//游戏结束
	settextstyle(30,20,"宋体");
	settextcolor(YELLOW);
	if (p_Winner == 0)
	{
		outtextxy(585, 300, "对局结束！");
	}
	else if (p_Winner == 1)
	{
		outtextxy(585, 300, "红方胜！");
	}
	else
	{
		outtextxy(585, 300, "白方胜！");
	}
	ifAgain();

}

void Play::ifAgain()
{
	int quit = MessageBox(NULL, "再来一局？", "请选择", MB_YESNO|MB_SYSTEMMODAL);
	if (quit == IDYES)
	{
		cleardevice();
		char title[20] = "五子棋大战";
		Window window(300, 300, 800, 600, title);
		window.drawWindow();
		window.drawChessBoard();	
	}
	else
	{
		cleardevice();
		settextstyle(50, 20, "宋体");
		outtextxy(300, 300, "欢迎再来");
		Sleep(1000);
		closegraph();
	}
}
bool Play::checkIsEnd()
{
	for (int i = 0; i < BLOCK; i++)
	{
		for (int j = 0; j < BLOCK; j++)
		{
			//左到右
			if (p_Winner==0&&i <= 10 && p_GameState[i][j] != 0 && p_GameState[i][j] == p_GameState[i][j + 1] && p_GameState[i][j] == p_GameState[i][j + 2] &&
				p_GameState[i][j] == p_GameState[i][j + 3] && p_GameState[i][j] == p_GameState[i][j + 4])
			{
				p_Winner = p_GameState[i][j];
				return true;
			}
			//上到下
			else if (p_Winner == 0 && j <= 10 && p_GameState[i][j] != 0 && p_GameState[i][j] == p_GameState[i + 1][j] && p_GameState[i][j] == p_GameState[i + 2][j] &&
				p_GameState[i][j] == p_GameState[i + 3][j] && p_GameState[i][j] == p_GameState[i + 4][j])
			{
				p_Winner = p_GameState[i][j];
				return true;
			}
			//左上到右下
			else if (p_Winner == 0 && i <= 10 && j <= 10 && p_GameState[i][j] != 0 && p_GameState[i][j] == p_GameState[i + 1][j + 1] && p_GameState[i][j] == p_GameState[i + 2][j + 2] &&
				p_GameState[i][j] == p_GameState[i + 3][j + 3] && p_GameState[i][j] == p_GameState[i + 4][j + 4])
			{
				p_Winner = p_GameState[i][j];
				return true;
			}
			//左下到右上
			else if (p_Winner == 0 && i <= 10 && j <= 10 && p_GameState[i][j] != 0 && p_GameState[i][j] == p_GameState[i - 1][j + 1] && p_GameState[i][j] == p_GameState[i - 2][j + 2] &&
				p_GameState[i][j] == p_GameState[i - 3][j + 3] && p_GameState[i][j] == p_GameState[i - 4][j + 4])
			{
				p_Winner = p_GameState[i][j];
				return true;
			}
			else
			{
				return false;
			}
		}
	}


}
