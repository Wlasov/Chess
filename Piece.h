#pragma once
#include "Color.h"
#include "Functions.h"
#include "Coordinate.h"

class Piece
{
public:
	Piece();
	Piece(EColor color);
	virtual ~Piece(){};
	
	virtual void Move(const Coordinate& nextPosition) = 0;
	
private:
	EColor _color;
};