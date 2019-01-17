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
			if (mouse.uMsg == WM_LBUTTONDBLCLK)//˫������
			{
				if (!p_GameState[i][j])//û���߹�����
				{
					addStepNum();//��һ������һ�μ���
					int playerNum = (getStepNum() + 1) % 2 + 1;//1Ϊ���֣�2Ϊ����
					p_GameState[i][j] = playerNum;
#pragma region ���Ծ����ֵ
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
					//�����Ѿ��߹�������
				}
			}


		}

	}
	//��Ϸ����
	settextstyle(30,20,"����");
	settextcolor(YELLOW);
	if (p_Winner == 0)
	{
		outtextxy(585, 300, "�Ծֽ�����");
	}
	else if (p_Winner == 1)
	{
		outtextxy(585, 300, "�췽ʤ��");
	}
	else
	{
		outtextxy(585, 300, "�׷�ʤ��");
	}
	ifAgain();

}

void Play::ifAgain()
{
	int quit = MessageBox(NULL, "����һ�֣�", "��ѡ��", MB_YESNO|MB_SYSTEMMODAL);
	if (quit == IDYES)
	{
		cleardevice();
		char title[20] = "�������ս";
		Window window(300, 300, 800, 600, title);
		window.drawWindow();
		window.drawChessBoard();	
	}
	else
	{
		cleardevice();
		settextstyle(50, 20, "����");
		outtextxy(300, 300, "��ӭ����");
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
			//����
			if (p_Winner==0&&i <= 10 && p_GameState[i][j] != 0 && p_GameState[i][j] == p_GameState[i][j + 1] && p_GameState[i][j] == p_GameState[i][j + 2] &&
				p_GameState[i][j] == p_GameState[i][j + 3] && p_GameState[i][j] == p_GameState[i][j + 4])
			{
				p_Winner = p_GameState[i][j];
				return true;
			}
			//�ϵ���
			else if (p_Winner == 0 && j <= 10 && p_GameState[i][j] != 0 && p_GameState[i][j] == p_GameState[i + 1][j] && p_GameState[i][j] == p_GameState[i + 2][j] &&
				p_GameState[i][j] == p_GameState[i + 3][j] && p_GameState[i][j] == p_GameState[i + 4][j])
			{
				p_Winner = p_GameState[i][j];
				return true;
			}
			//���ϵ�����
			else if (p_Winner == 0 && i <= 10 && j <= 10 && p_GameState[i][j] != 0 && p_GameState[i][j] == p_GameState[i + 1][j + 1] && p_GameState[i][j] == p_GameState[i + 2][j + 2] &&
				p_GameState[i][j] == p_GameState[i + 3][j + 3] && p_GameState[i][j] == p_GameState[i + 4][j + 4])
			{
				p_Winner = p_GameState[i][j];
				return true;
			}
			//���µ�����
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
