#include "Game.h"

Game::Game(EGameType gt): _gameType(gt)
{
}

Game::~Game()
{
	
}
	
void Game::Start()
{
	int input;
	
	if (_gameType == EGameType::EightQueensProblem)
	{
		std::cout<<"Введите размер доски";
		std::cin>>input;
	}
	
	Queens* q = new Queens(input);
	q->FindAllSolutions(0);
}

void Game::End()
{
	
}