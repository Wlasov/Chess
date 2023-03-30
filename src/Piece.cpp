#include "Piece.h"

Piece::Piece(){};

Piece::Piece(EColor color, std::string sign): _color(color), _sign(sign){}

const EColor& Piece::GetColor()
{
	return _color;
}

Piece::Piece(const Piece& piece)
{
    _color = piece._color;
}

Piece& Piece::operator=(const Piece& other)
{
    _color = other._color;
    return *this;
}

std::ostream& operator << (std::ostream& os, const Piece& piece)
{
	return os << piece._sign;
}

bool Piece::operator== (std::nullptr_t)
{
	return true;
}

//return _color == target._color && _sign == target._sign;