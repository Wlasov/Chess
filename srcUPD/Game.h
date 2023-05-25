#pragma once
#include "Queens.h"

enum EGameType
{
	Chess,
	EightQueensProblem
};

class Game
{
public:
	Game(EGameType gt);
	~Game();
	
	void Start();
	void End();
	
private:
	EGameType _gameType;
};