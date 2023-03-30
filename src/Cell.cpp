#include "Cell.h"

Cell::Cell(){}

Cell::Cell(EColor color, Coordinate* coordinate, Piece* piece):
	_color(color),
	_currentCoordinate(coordinate),
	_currentPiece(piece)
	{}

Cell::~Cell(){}

Cell::Cell(const Cell& cell)
{
    _currentPiece = cell._currentPiece;
    _color = cell._color;
    _currentCoordinate = cell._currentCoordinate;
}

Cell& Cell::operator=(const Cell& other)
{
    _currentPiece = other._currentPiece;
    _color = other._color;
    _currentCoordinate = other._currentCoordinate;
    return *this;
}

std::ostream& operator << (std::ostream& os, const Cell& cell)
{
    return os << ColorToString(cell._color);
}

const EColor& Cell::GetColor()
{
	return _color;
}

const Coordinate* Cell::GetCoordinate()
{
	return _currentCoordinate;
}

Piece* Cell::GetPiece()
{
	return _currentPiece;
}