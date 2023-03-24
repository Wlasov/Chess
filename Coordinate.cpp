#include "Coordinate.h"

Coordinate::Coordinate() {}

Coordinate::Coordinate(size_t col, size_t row): _col(col), _row(row) {};

const size_t& Coordinate::GetColumn()
{
	return _col;
}

const size_t& Coordinate::GetRow()
{
	return _row;
}