#include "Board.h"

Board::Board() {}

Board::Board(size_t size): _size(size)
{
    _cells = new Cell[size*size];
    int currentCell = 0;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            _cells[currentCell] = Cell( (i+j) % 2 ? Black : White , new Coordinate(i, j));
            ++currentCell;
        }
    }	
}

std::ostream& operator << (std::ostream& os, const Board& board)
{
    int currentCell = 0;
    for (int i = 0; i < board._size; ++i)
    {
        os << board._size - i;
        for (int j = 0; j < board._size; ++j, ++currentCell)
        {
            os << board._cells[currentCell];      
        }    
        os << "\n";
    }    
    os << ' ';    
    for (int i = 0; i < board._size; ++i)
    {
        os << (char)(65+i) << ' ';
    }    
    os << '\n';  
	
    return os;
}
