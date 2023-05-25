#pragma once
#include "Cell.h"

class Board
{
public:
	Board();
	Board(size_t size);
	~Board(){};
	friend std::ostream& operator << (std::ostream& os, const Board& board);
	void DebugPrint(); // print board from h8 to a1
	void DebugPrintPlayerPerspective(); // print board from a1 to h8
	void PlacePiece(Coordinate* coord, BasePiece* piece); // Place "piece" on "coord"
	void RemovePiece(Coordinate* coord);
	size_t& GetSize();
	Cell& GetCell(int id); // get cell by id: id(0) -> A1, id(9) -> B2, id(63) -> H8 ...
	Cell& GetCell(int col, int row); // get cell by position: Position(0, 0) -> A1, Position(1, 1) -> B2, Position(7,7) -> H8 ...
	bool IsEmpty(); // checks if there are pieces on the board
	
private:
	size_t _size = 0; // size of board
	Cell* _cells = nullptr; // board's cells
};
