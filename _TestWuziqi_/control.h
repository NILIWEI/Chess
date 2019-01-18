#pragma once
class Control
{
	
private:
	 int c_State;//游戏的状态，0表示初始状态，1表示游戏中状态
	 int c_Winner;//0表示没有胜负，1表示玩家1胜利，2表示玩家2胜利
	 bool c_Net;//是否进行联网游戏

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
