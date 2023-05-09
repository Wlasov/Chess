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
	
	void FindAllSolutions(int line);
	void PrintAllSolutions();
	
private:
	Board* _solutions = nullptr;
	Board* _board = nullptr;
	size_t _solutionsCount = 0;
	bool TryPlace(int, int);
};