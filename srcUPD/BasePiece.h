#pragma once
#include "Color.h"
#include <iostream>

class BasePiece
{
public:
	BasePiece();
	BasePiece(EColor color, std::string sign);
	virtual ~BasePiece() {};
	friend std::ostream& operator << (std::ostream& os, const BasePiece& piece);
	
	// Getters
	EColor& GetColor();
	std::string& GetSign();
	
private:
	EColor _color = EColor::NoColor; //color of the piece
	std::string _sign = ""; //the sign that is displayed in the console
};
