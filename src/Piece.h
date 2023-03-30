#pragma once
#include "Color.h"
#include "Functions.h"
#include "Coordinate.h"

class Piece
{
public:
	Piece();
	Piece(EColor color, std::string sign);
	virtual ~Piece(){};
	const EColor& GetColor();
	Piece(const Piece& Piece);
	Piece& operator=(const Piece& other);
	friend std::ostream& operator << (std::ostream& os, const Piece& piece);
	bool operator== (std::nullptr_t);
	
private:
	EColor _color;
	std::string _sign = "";
};