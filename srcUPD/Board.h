#pragma once
#include "Cell.h"

class Board
{
public:
	Board();
	Board(size_t size);
	~Board(){};
	friend std::ostream& operator << (std::ostream& os, const Board& board);
	void DebugPrint();
	void DebugPrintPlayerPerspective();
	void PlacePiece(Coordinate* coord, BasePiece* piece);
	void RemovePiece(Coordinate* coord);
	size_t& GetSize();
	Cell& GetCell(int id);
	Cell& GetCell(int col, int row);
	bool IsEmpty();
	
private:
	size_t _size = 0;
	Cell* _cells = nullptr;
};