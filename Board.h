#pragma once
#include <iostream>
#include "Cell.h"
#include "Coordinate.h"

class Board
{
public:
    Board();
    Board(size_t size);
    friend std::ostream& operator << (std::ostream& os, const Board& board);
    ~Board();
	
private:
    size_t _size;
    Cell* _cells;
};
