#pragma once
class Control
{
	
private:
	 int c_State;//��Ϸ��״̬��0��ʾ��ʼ״̬��1��ʾ��Ϸ��״̬
	 int c_Winner;//0��ʾû��ʤ����1��ʾ���1ʤ����2��ʾ���2ʤ��
	 bool c_Net;//�Ƿ����������Ϸ

public:
	friend class Play;

	Control();
	~Control();
	void startGame();
	void endGame();

	inline bool  getNet() { return c_Net; };
	inline int getState() { return c_State; };
	inline int getWinner() { return c_Winner; };
	inline void setState(int state) { c_State = state; };
	inline void setWinner(int winner) { c_Winner = winner; };

	

};
