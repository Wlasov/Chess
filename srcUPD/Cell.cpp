#include "Cell.h"
#include "color.hpp"

std::string ColorToString(EColor color)
{
	switch (color)
    {
        case 0:
            return BLACK_SQUARE_SIGN;
        case 1:
            return  WHITE_SQUARE_SIGN;
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
	#if defined(_WIN32)
		if (cell.IsEmpty())
		{
			return cell._color ? os << dye::on_green("  ") : os << dye::on_grey("  ");
		}
		else
		{
			return cell._color ? os << dye::on_green(*cell._currentPiece) : os << dye::on_grey(*cell._currentPiece);
		}
	#endif
	
    return cell.IsEmpty() ? os << ColorToString(cell._color) : os << cell._currentPiece;
}

EColor Cell::GetColor()
{
	return _color;
}

BasePiece* Cell::GetPiece()
{
	return _currentPiece;
}