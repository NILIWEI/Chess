//#include<graphics.h>
//#include<conio.h>
//#include<Windows.h>
//#include<stdio.h>
//#include<time.h>
//
//#pragma warning(disable:4996)
//void menu();
//void play();
//void display();
//void playgame();
//void again(int index);
//int a[9][9] = { 0 };
//
//void main()
//{
//	initgraph(600, 600, SHOWCONSOLE);
//	menu();
//	getch();
//}
//
//void menu()
//{
//	IMAGE img;
//	setaspectratio(1.1, 1);
//	loadimage(&img, "IMAGE", "tur", 0, 0, true);
//	putimage(-10, 0, &img, SRCPAINT);
//	settextstyle(50, 20, "����");
//	outtextxy(200, 400, "��ʼ��Ϸ");
//	MOUSEMSG m;
//	while (true)
//	{
//		m = GetMouseMsg();
//		if (m.uMsg == WM_MOUSEMOVE && m.x >= 200 && m.x <= 360 && m.y >= 400 && m.y <= 450)
//		{
//			setlinecolor(YELLOW);
//			rectangle(200, 400, 360, 450);
//
//		}
//		if (m.uMsg == WM_LBUTTONDOWN && m.x >= 200 && m.x <= 360 && m.y >= 400 && m.y <= 450)
//		{
//			cleardevice();
//			Sleep(500);
//			play();
//			break;
//		}
//		if (!(m.x >= 200 && m.x <= 360 && m.y >= 400 && m.y <= 450))
//		{
//			setlinecolor(BLACK);
//			rectangle(200, 400, 360, 450);
//		}
//	}
//}
//
//void play()
//{
//	graphdefaults();
//	setlinecolor(WHITE);
//	settextstyle(15, 10, "����");
//	settextcolor(WHITE);
//	outtextxy(460, 80, "play1:����:");
//	outtextxy(460, 100, "����: ");
//	outtextxy(460, 160, "play2:����");
//	outtextxy(460, 180, "����: ");
//	display();
//}
//
//void display()
//{
//	for (int i = 50; i <= 450; i += 50)
//	{
//		line(i, 50, i, 450);
//		line(50, i, 450, i);
//	}
//	playgame();
//}
//void playgame()
//{
//	char str1[5];
//	char str2[5];
//	int bushu1 = 0, bushu2 = 0;
//	memset(a, 0, sizeof(a));
//	int play1 = 1;
//	int i = 0, j = 0;
//	int win = 0;
//	MOUSEMSG msg;
//	while (win == 0)
//	{
//		msg = GetMouseMsg();
//		if (msg.uMsg == WM_LBUTTONDOWN)
//		{
//			for (int lie = 50; lie <= 450; lie += 50)
//			{
//				if (msg.x <= lie + 10 && msg.x >= lie - 10)
//				{
//					for (int hang = 50; hang <= 450; hang += 50)
//					{
//						if (msg.y <= hang + 10 && msg.y >= hang - 10)
//						{
//							if (play1 == 1 && a[hang / 50 - 1][lie / 50 - 1] == 0)
//							{
//								setfillcolor(RED);
//								solidcircle(lie, hang, 12);
//								a[hang / 50 - 1][lie / 50 - 1] = 1;
//								play1 = 0;
//								bushu1++;
//								sprintf(str1, "%i", bushu1);
//								outtextxy(520, 100, str1);
//								break;
//							}
//							if (play1 == 0 && a[hang / 50 - 1][lie / 50 - 1] == 0)
//							{
//								setfillcolor(YELLOW);
//								solidcircle(lie, hang, 12);
//								a[hang / 50 - 1][lie / 50 - 1] = 2;
//								play1 = 1;
//								bushu2++;
//								sprintf(str2, "%i", bushu2);
//								outtextxy(520, 180, str2);
//								break;
//							}
//						}
//					}
//				}
//			}
//		}
//		//�ж��Ƿ�Ӯ
//		for (j = 0; j < 9 && (win == 0); j++)
//		{
//			for (i = 0; i < 6; i++)
//			{
//
//				if ((a[j][i] == 1 && a[j][i + 1] == 1 && a[j][i + 2] == 1 && a[j][i + 3] == 1 && a[j][i + 4] == 1)
//					|| (a[i][j] == 1 && a[i + 1][j] == 1 && a[i + 2][j] == 1 && a[i + 3][j] == 1 && a[i + 4][j] == 1))//������5����play1 win
//				{
//					win = 1;
//					Sleep(100);
//					break;
//				}
//				if ((a[j][i] == 2 && a[j][i + 1] == 2 && a[j][i + 2] == 2 && a[j][i + 3] == 2 && a[j][i + 4] == 2)
//					|| (a[i][j] == 2 && a[i + 1][j] == 2 && a[i + 2][j] == 2 && a[i + 3][j] == 2 && a[i + 4][j] == 2))//������5����play2 win
//				{
//					win = 2;
//					Sleep(100);
//					break;
//				}
//			}
//		}
//		for (j = 0; j < 6 && (win == 0); j++)
//		{
//			for (i = 0; i < 6; i++)
//			{
//				if (a[j][i] == 1 && a[j + 1][i + 1] == 1 && a[j + 2][i + 2] == 1 && a[j + 3][i + 3] == 1 && a[j + 4][i + 4] == 1)//������бʱ��play1 win
//				{
//					win = 1;
//					Sleep(100);
//					break;
//
//				}
//				if (a[j][i] == 2 && a[j + 1][i + 1] == 2 && a[j + 2][i + 2] == 2 && a[j + 3][i + 3] == 2 && a[j + 4][i + 4] == 2)//������бʱ��play2 win
//				{
//					win = 2;
//					Sleep(100);
//					break;
//				}
//			}
//			for (i = 4; i < 9 && (win == 0); i++)
//			{
//				if (a[j][i] == 1 && a[j + 1][i - 1] == 1 && a[j + 2][i - 2] == 1 && a[j + 3][i - 3] == 1 && a[j + 4][i - 4] == 1)//������бʱ��play1 win
//				{
//					win = 1;
//					Sleep(100);
//					break;
//				}
//				if (a[j][i] == 2 && a[j + 1][i - 1] == 2 && a[j + 2][i - 2] == 2 && a[j + 3][i - 3] == 2 && a[j + 4][i - 4] == 2)//������бʱ��play2 win
//				{
//					win = 2;
//					Sleep(100);
//					break;
//				}
//			}
//		}
//	}
//	again(win);
//}
//void again(int index)
//{
//	settextstyle(20, 20, "����");
//	settextcolor(YELLOW);
//	if (index == 1)
//	{
//		outtextxy(220, 500, "play1 win!");
//	}
//	else
//	{
//		outtextxy(220, 500, "play2 win!");
//	}
//	int quit = MessageBox(NULL, "�Ƿ������Ϸ", "ArchyLi", MB_YESNO);
//	if (IDYES == quit)
//	{
//		cleardevice();
//		play();
//	}
//	else
//	{
//		cleardevice();
//		settextstyle(50, 30, "����");
//		settextcolor(YELLOW);
//		outtextxy(200, 300, "��ӭ�´�����");
//		Sleep(1000);
//		return;
//	}
//}
