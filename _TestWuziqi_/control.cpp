#include"control.h"
#include"window.h"
#include<cstdio>
Control::Control()
{
	c_State = 0;
	c_Winner = 0;
}
Control::~Control()
{
	Window::closeWindow();
}

void Control::startGame()
{
	setState(1);
}

void Control::endGame()
{
	c_State = 0;//游戏结束后将游戏设置成未游戏状态
}
