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
	bool IsEmpty() const;
	Cell(const Cell& cell);
	Cell& operator=(const Cell& other);
	friend std::ostream& operator << (std::ostream& os, const Cell& cell);
	EColor GetColor();
	BasePiece* GetPiece();
	
private:
	Coordinate* _coordinate = nullptr;
	EColor _color = EColor::NoColor;
	BasePiece* _currentPiece = nullptr;
};