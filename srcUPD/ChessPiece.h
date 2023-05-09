#pragma once
#include "BasePiece.h"

class Pawn: public BasePiece
{
public:
	Pawn(EColor color): BasePiece(color, color ? "\u2659 " : "\u265F") {};
	~Pawn() {};
};

class Queen: public BasePiece
{
public:
	Queen(EColor color): BasePiece(color, color ? "\u265B " : "\u2655 ") {};
	~Queen() {};
};