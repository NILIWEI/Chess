#pragma once
#define BLOCK 15
class Play
{
private:
	int p_GameState[BLOCK][BLOCK];
	int p_StepNum;
	int p_Winner;
public:
	Play(int gameState[BLOCK][BLOCK]);
	~Play();

	void initPlay();
	void dropChess();

	inline void addStepNum() { p_StepNum++; };
	inline int getStepNum() { return p_StepNum; };
	bool checkIsEnd();
	void ifAgain();
};