#include "Board.h"

Board::Board() {}

Board::Board(size_t size): _size(size)
{
	_cells = new Cell[size*size];
    int currentCell = 63;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            _cells[currentCell] = Cell( (i+j) % 2 ? Black : White , new Coordinate(i, j));
            --currentCell;
        }
    }	
}

/*

*/

std::ostream& operator << (std::ostream& os, const Board& board)
{
	int currentCell = 0;
	
    for (int i = 0; i < board._size; ++i)
    {
        os << board._size-i;
        for (int j = 0; j < board._size; ++j, ++currentCell)
        {
			if (board._cells[currentCell].GetPiece() == nullptr)
				os << board._cells[currentCell];  
			else
				os << *board._cells[currentCell].GetPiece();
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

size_t ColCoordinateToInt(const std::string& coordinate)
{
	if (coordinate.size() == 2)
	{
		return (int)(coordinate[0])-97;
	}
	
	return -1;
}

size_t RowCoorinateToInt(const std::string& coordinate)
{
	if (coordinate.size() == 2)
	{
		return (int)(coordinate[1])-49;
	}
	
	return -1;
}

const size_t& Board::GetSize()
{
	return _size;
}

void Board::PlacePiece(const std::string& coordinate, Piece* piece)
{
	size_t col = ColCoordinateToInt(coordinate);
	size_t row = _size - 1 - RowCoorinateToInt(coordinate);
	
	EColor tmpColor = _cells[_size*col+row].GetColor();
	Coordinate* tmpCoord = new Coordinate(col, row);
	
	_cells[_size*row+col] = Cell(tmpColor, tmpCoord, piece);	
}

void RemovePiece(std::string& coordinate, Piece& piece);

void Board::MovePiece(const std::string& from, const std::string& to, EInputMode = PlayerInput)
{
	size_t col = ColCoordinateToInt(from);
	size_t row = _size - 1 - RowCoorinateToInt(from);
	EColor tmpColor = _cells[_size*col+row].GetColor();
	Coordinate* tmpCoord = new Coordinate(col, row);
	
	Piece* tmpPiece = _cells[_size*row+col].GetPiece();
	
	size_t toCol = ColCoordinateToInt(to);
	size_t toRow = _size - 1 - RowCoorinateToInt(to);
	EColor tmpToColor = _cells[_size*toCol+toRow].GetColor();
	Coordinate* tmpToCoord = new Coordinate(toCol, toRow);
	
	_cells[_size*toRow+toCol] = Cell(tmpToColor, tmpToCoord, tmpPiece);
	_cells[_size*row+col] = Cell(tmpColor, tmpCoord);
	
	std::cout<<"moved from "<<from<<" "<<"to "<<to<<"\n";
}

void Board::DebugPrint()
{
	int x = 0;
	
	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < _size; ++j)
		{
			if (_cells[x].GetPiece() != nullptr)
			{
				std::cout<<"x";
			}
			
			std::cout<<_cells[x];
			++x;
		}
		
		std::cout<<'\n';
	}
}