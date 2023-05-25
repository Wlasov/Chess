#pragma once
#include "Queens.h"

// Type of games
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
	
	void Start(); // start game
	void End(); // end game
	
private:
	EGameType _gameType; // type of game
};
