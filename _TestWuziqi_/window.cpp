#include"window.h"
#include<Windows.h>
#include<graphics.h>
Window::Window(int xpos, int ypos, int width, int height, char* title)
	:w_Xpos(xpos), w_Ypos(ypos), w_Width(width), w_Height(height), w_Title(title)
{

}
Window::~Window()
{
	w_Width = 0;
	w_Height = 0;
	w_Title = nullptr;
}

Window::Window(const Window& window)
{
	w_Width = window.w_Width;
	w_Height = window.w_Height;
	w_Xpos = window.w_Xpos;
	w_Ypos = window.w_Ypos;
	//�������ò�����������ʵ����titleָ��ͬһ��ָ��
	w_Title = new char[strlen(window.w_Title) + 1];
	if (w_Title)
	{
		w_Title = window.w_Title;
	}

}

void Window::setPostion(const int& xpos, const int& ypos)
{
	w_Xpos = xpos;
	w_Ypos = ypos;
}
void Window::setSize(const int& width, const int& height)
{
	w_Width = width;
	w_Height = height;
}
void Window::setTitle(char* title)
{
	w_Title = title;
}

void Window::drawWindow()
{

	initgraph(w_Width, w_Height);//����һ��������С�Ĵ���
	//setorigin(w_Xpos, w_Ypos);
}

void Window::closeWindow()
{
	closegraph();
}
void Window::drawChessBoard()
{
	//setbkcolor(BLUE);
	//setlinecolor(BLACK);
	for (int temp = 38; temp<=570; temp+=38)
	{
		setlinecolor(MAGENTA);
		settextstyle(24,16,"����");
		outtextxy(10,2,"��Ϸ����˫�����壬�������У�������У�");


		setlinecolor(WHITE);
		line(temp, 38, temp, 570);
		line(38, temp, 570, temp);

		setlinecolor(LIGHTRED);
		rectangle(580,100,780,160);
		settextstyle(14, 10, "����");
		settextcolor(LIGHTRED);
		outtextxy(585,123,"���1��������");

		setlinecolor(WHITE);
		rectangle(580, 400, 780, 460);
		settextstyle(14, 10, "����");
		settextcolor(WHITE);
		outtextxy(585, 423, "���2��������");

	}


}
