#include "Queens.h"

Queens::Queens(){};

void Queens::MovePiece(const std::string& from, const std::string& to) {}

Queens::Queens(size_t boardSize): _board(new Board(boardSize)){}

bool Queens::TryPlace(int col, int row)
{	
	int size = _board->GetSize();
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (!_board->GetCell(i, row).IsEmpty()) 
				return false;
		}
	}
	
	for(int i = 1; i <= col && row-i >= 0; ++i)
    	{
		if (!_board->GetCell(col - i, row - i).IsEmpty()) 
			return false;
    	}
	
	for(int i = 1; i <= col && row+i < size; i++)
    	{
		if (!_board->GetCell(col - i, row + i).IsEmpty())
			return false;
    	}
	
	return true;
}

void Queens::FindAllSolutions(int line)
{
	_solutions = new Board[50000];
	
	if (line == _board->GetSize())
	{
		_solutions[_solutionsCount] = *_board;
		_solutionsCount++;
		std::cout<<*_board<<"\n\n";
		return;
	}
	
	for(int i = 0; i < _board->GetSize(); ++i)
    	{
		if(TryPlace(line, i))
		{
			_board->PlacePiece(new Coordinate(line, i), new Queen(White));
			FindAllSolutions(line+1);
			_board->RemovePiece(new Coordinate(line, i));
		}
   	}
}

void Queens::PrintAllSolutions()
{
	for (int i = 0; i < 100; i++)
	{
		std::cout<<_solutions[0];
	}
}
