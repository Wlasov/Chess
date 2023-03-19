#include <iostream>
#include <typeinfo>

class Cell;
class Piece;
class Board;
class GameManager;

enum EColor
{
    Black = 0,
    White,
};

std::string ColorToString(EColor color)
{
    switch (color)
    {
        case 0:
            return "\u25A0 ";
        case 1:
            return  "\u25A1 ";
        default:
            return "  ";
    }
}

std::string BlackPieceToString(Piece& piece)
{
    return "\u265F ";
}

std::string WhitePieceToString(Piece& piece)
{
    return "\u2659 ";
}

struct Position
{
    size_t col, row;
    
    Position(size_t col, size_t row) : col(col), row(row) {}
};

class Piece
{
public:
    Piece() {}
    Piece(EColor color): _color(color) {}
    
    virtual void Move(Cell& nextCell) = 0;
    virtual ~Piece() {};
    
    const EColor GetColor() { return _color; }
    
    friend std::ostream& operator << (std::ostream& os, Piece& piece)
    {
        return piece.GetColor() ? os << BlackPieceToString(piece): os << WhitePieceToString(piece);
    }
    
private:
    EColor _color;
};

class Pawn: public Piece
{
public: 
    Pawn(EColor color): Piece(color){}
    
    void Move(Cell& nextCell){}
}; 

class Knight: public Piece {}; 

class Bishop: public Piece {}; 

class Rook: public Piece {}; 

class Queen: public Piece {};

class King: public Piece {}; 

class Cell
{
public:
    Cell(){}
    
    Cell(EColor color, Position* position, Piece* piece = NULL) 
    : _color(color)
    , _currentPosition(position)
    , _currentPiece(piece){}
    
    Cell(const Cell& cell)
    {
        _currentPiece = cell._currentPiece;
        _color = cell._color;
        _currentPosition = cell._currentPosition;
    }
    
    Cell& operator=(const Cell& other)
    {
        _currentPiece = other._currentPiece;
        _color = other._color;
        _currentPosition = other._currentPosition;
        return *this;
    }
    
    friend std::ostream& operator << (std::ostream& os, const Cell& cell)
    {
        return os << ColorToString(cell._color);
    }
    
    ~Cell(){}
    
    EColor GetColor()
    {
        return _color;
    }
    
    const Position& GetPosition()
    {
        return *_currentPosition;
    }
    
private:
    Piece* _currentPiece;
    EColor _color;
    Position* _currentPosition;
};

class Board
{
public:
    Board(){}
    Board(size_t size): _size(size)
    {
        _cells = new Cell[size*size];
        int currentCell = 0;
        
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                _cells[currentCell] = Cell( (i+j) % 2 ? Black : White , new Position(i, j));
                ++currentCell;
            }
        }
    }
    
    friend std::ostream& operator << (std::ostream& os, const Board& board)
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
    
    ~Board();
    
    
    
private:
    size_t _size;
    Cell* _cells;
};

class GameManager
{
public:
    GameManager();
    virtual ~GameManager();
    
private:
    Piece* whitePieces;
    Piece* blackPieces;
};

int main(void)
{
    Pawn* p = new Pawn(White);
    std::cout<<*p;
    

}
