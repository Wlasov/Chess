#include "BasePiece.h"

BasePiece::BasePiece(){}

BasePiece::BasePiece(EColor color, std::string sign): _color(color), _sign(sign){}

std::ostream& operator << (std::ostream& os, const BasePiece& piece)
{
	return os << piece._sign;
}

EColor& BasePiece::GetColor()
{
	return _color;
}

std::string& BasePiece::GetSign()
{
	return _sign;
}