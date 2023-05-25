#pragma once
#include <iostream>

class Coordinate
{
public:
	Coordinate();
	Coordinate(size_t col, size_t row);	
	~Coordinate();
	
	size_t& GetColumn();
	size_t& GetRow();

private:
	size_t _col; // board's column
	size_t _row; // board's row
}; 

/*
	Coordinate(0, 0) means A1,
	Coordinate(1, 1) means B2,
	Coordinate(7, 7) means H8,
*/
