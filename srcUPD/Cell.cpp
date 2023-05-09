#include "Cell.h"

std::string ColorToString(EColor color)
{
	switch (color)
    {
        case 0:
            return "\u25A0";
        case 1:
            return  "\u25A1";
        default:
            return "  ";
    }
}

Cell::Cell() {};

Cell::Cell(Coordinate* coord, EColor color, BasePiece* piece):
	_coordinate(coord),
	_color(color),
	_currentPiece(piece){}
	
bool Cell::IsEmpty() const 
{
	return _currentPiece == NULL;
}

Cell::Cell(const Cell& cell)
{
    _currentPiece = cell._currentPiece;
    _color = cell._color;
    _coordinate = cell._coordinate;
}

Cell& Cell::operator=(const Cell& other)
{
    _currentPiece = other._currentPiece;
    _color = other._color;
    _coordinate = other._coordinate;
    return *this;
}

std::ostream& operator << (std::ostream& os, const Cell& cell)
{
	return cell.IsEmpty() ? os << ColorToString(cell._color) : os << *cell._currentPiece;
}

EColor Cell::GetColor()
{
	return _color;
}