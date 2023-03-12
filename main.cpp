#include <iostream>

enum EColor
{
	Black = 0,
	White
};

struct Position
{
	int col, row;
	
	Position(int col = 0, int row = 0)
	{
		this->col = col;
		this->row = row;
	}
};

class Piece
{
public:
	Piece(const EColor color, const Position position)
	{
		_color = color;
		_currentPosition = position;
	}

	virtual void Move(const Position& nextPosition) = 0;
	virtual void Eat(const Piece& target) = 0;
	virtual ~Piece() {}
	
private:
	EColor _color;
	Position _currentPosition;
};

class Cell
{
public:
	Cell(const EColor color = Black)
		: _color(color)	
	{}
	~Cell(){}
	
	Cell(const Cell& cell)
	  : _color(cell._color)
	  , _currentPiece(cell._currentPiece)
	{}
	
	Cell& operator= (const Cell& cell)
	{
		_color = cell._color;
		_currentPiece = cell._currentPiece; 
		return *this;
	} 
	
	void PlaceFigure(Piece* piece)
	{
		_currentPiece = piece;
	}
	
	EColor GetColor()
	{
		return _color;
	}
	
	const Piece& GetPiece()
	{
		return *_currentPiece;
	}
		
private:
	EColor _color;
	Piece* _currentPiece;
};

class Board
{
public:
	Board(const size_t size)
	{
		_size = size;
		
		_cells = new Cell[size*size];
		
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				_cells[i+j] = new Cell();
			}
		}
	}
	
private:
	size_t _size;
	Cell* _cells;
};

int main()
{
	Board* board = new Board(8);

	return 0;
}
