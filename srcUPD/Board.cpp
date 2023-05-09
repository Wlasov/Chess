#include "Board.h"

Board::Board(){}

Board::Board(size_t size): _size(size)
{
	_cells = new Cell[size*size];
	int currCell = 0;
	
	for (int col = 0; col < size; ++col)
	{
		for (int row = 0; row < size; ++row, ++currCell)
		{
			_cells[currCell] = Cell(new Coordinate(col, row), (col + row) % 2 ? Black : White);
		}
	}
}

void Board::DebugPrint()
{
	int currCell = 0;
	
	std::cout<<" ";
	for (int i = 0; i < _size; ++i)
		std::cout<<(char)(65+i)<<' ';
	std::cout<<'\n';
	
	for (int col = 0; col < _size; ++col)
	{
		std::cout<<col+1;
		for (int row = 0; row < _size; ++row, ++currCell)
		{
			std::cout<<_cells[currCell];
		}
		std::cout<<'\n';
	}
}

void Board::PlacePiece(Coordinate* coord, BasePiece* piece)
{
	int col = coord->GetColumn();
	int row = coord->GetRow();
	int id = _size*col+row;
	_cells[id] = Cell(new Coordinate(col, row), _cells[id].GetColor(), piece);
}

void Board::RemovePiece(Coordinate* coord)
{
	int col = coord->GetColumn();
	int row = coord->GetRow();
	int id = _size*col+row;
	_cells[id] = Cell(new Coordinate(col, row), _cells[id].GetColor());
}

void Board::DebugPrintPlayerPerspective()
{
	int currCell = 0;
	int tmpSize = _size*_size - _size;
	
	for (int col = 0; col < _size; ++col)
	{
		std::cout<<_size-col;
		for (int row = 0; row < _size; ++row, ++currCell)
		{
			std::cout<<_cells[tmpSize+row];
		}
		tmpSize -= _size;
		std::cout<<'\n';
	}
	std::cout<<" ";
	for (int i = 0; i < _size; ++i)
		std::cout<<(char)(65+i)<<" ";
}

std::ostream& operator << (std::ostream& os, const Board& board)
{
	int currCell = 0;
	int tmpSize = board._size*board._size - board._size;
	
	for (int col = 0; col < board._size; ++col)
	{
		os<<board._size-col;
		for (int row = 0; row < board._size; ++row, ++currCell)
		{
			os<<board._cells[tmpSize+row];
		}
		tmpSize -= board._size;
		os<<'\n';
	}
	os<<" ";
	for (int i = 0; i < board._size; ++i)
		os<<(char)(65+i)<<" ";
	
	return os;
}

size_t& Board::GetSize()
{
	return _size;
}

Cell& Board::GetCell(int id)
{
	return _cells[id];
}

Cell& Board::GetCell(int col, int row)
{
	return _cells[_size*col+row];
}

bool Board::IsEmpty()
{
	return _size == 0;
}