#pragma once
#include "Piece.h"
#include <iostream>
#include "Color.h"
#include "Coordinate.h"

class Cell
{
public:
	Cell();
	Cell(EColor color, Coordinate* coordinate, Piece* piece = nullptr);
	Cell(const Cell& cell);
	Cell& operator=(const Cell& other);
	friend std::ostream& operator << (std::ostream& os, const Cell& cell);
	~Cell();
	
	const EColor& GetColor();
	const Coordinate* GetCoordinate();
	Piece* GetPiece();
	
private:
	Piece* _currentPiece = nullptr;
	EColor _color;
	Coordinate* _currentCoordinate;
};