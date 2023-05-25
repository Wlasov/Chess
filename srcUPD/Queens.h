#pragma once
#include "IGameRules.h"
#include "ChessPiece.h"

class Queens: public IGameRules
{
public:
	Queens();
	Queens(size_t boardSize);
	void MovePiece(const std::string& from, const std::string& to) override;
	~Queens();
	
	void FindAllSolutions(int line); // finds all solutions for problem N queens for N board.
	void PrintAllSolutions(); // prints solutions.
	
private:
	Board* _solutions = nullptr; // an array of boards containing solutions to the n-queens problem.
	Board* _board = nullptr; // board 0_0
	size_t _solutionsCount = 0; // total solutuins count. for 8x8 board - 92.
	bool TryPlace(int, int); // trying place Queen on Coordinate(x, y);
};
