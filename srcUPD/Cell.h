#pragma once
#include "BasePiece.h"
#include "Coordinate.h"
#include "Signs.h"

class Cell
{
public:
	Cell();
	Cell(Coordinate* coord, EColor color, BasePiece* piece = nullptr);
	~Cell() {};
	bool IsEmpty() const; // checks if there is a piecee on this cell
	Cell(const Cell& cell);
	Cell& operator=(const Cell& other);
	friend std::ostream& operator << (std::ostream& os, const Cell& cell);
	EColor GetColor();
	BasePiece* GetPiece();
	
private:
	Coordinate* _coordinate = nullptr; // coordinate of cell ( Coordinate(0, 0) means A1, Coordinate(7, 7) means H8...
	EColor _color = EColor::NoColor; // Color of the cell
	BasePiece* _currentPiece = nullptr; // the figure that stands on this cell
};
