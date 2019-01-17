#pragma once
class Window
{
private:
	int	 w_Width;
	int	 w_Height;
	int	 w_Xpos;
	int	 w_Ypos;
	char *w_Title;


public:

	friend class Play;
	Window(int xpos, int ypos, int width, int height, char* title);
	~Window();
	//������һ����ĳ�Ա������ָ�룬���붨�帴�ƹ��캯��
	Window(const Window& window);
	void setPostion(const int& xpos, const int& ypos);
	void setSize(const int& width, const int& height);
	void setTitle(char* title);
	void drawWindow();
	static void closeWindow();
	void drawChessBoard();

};
