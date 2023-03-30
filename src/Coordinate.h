#pragma once
#include <iostream>

class Coordinate
{
public:
	Coordinate();
	Coordinate(size_t col, size_t row);	
	~Coordinate();
	
	const size_t& GetColumn();
	const size_t& GetRow();

private:
	size_t _col;
	size_t _row;
};