#include <iostream>

// Цвет клетки и фигуры
enum EColor
{
    Black = 0,
    White,
};

// Перерводит енум цвета в белый или черный квадратик
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

// позиция, позволяет линейный массив клеток представить в виде 2мерного массива
struct Position
{
    uint16_t col, row;
    
    Position(uint16_t col, uint16_t row) : col(col), row(row) {}
};

// базовый класс фигуры
class Piece
{
public:
    virtual void Move(Position& nextPosition) = 0;
    virtual bool IsMoveValiable(const Position& nextPosition) = 0;
    virtual void Eat(Piece& target) = 0;
    virtual ~Piece() {};
    
private:
    EColor _color;
};

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
    Board(size_t size)
    {
        _size = size;
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
    
    ~Board();
    
    void Print()
    {
        int currentCell = 0;
        
        for (int i = 0; i < _size; ++i)
        {
            std::cout<< _size - i << ' ';
            
            for (int i = 0; i < _size; ++i)
            {
                std::cout<<ColorToString(_cells[currentCell].GetColor());
                ++currentCell;
            }
            
            std::cout<<'\n';
        }
        
        std::cout << "  ";
        
        for (int i = 0 ; i < _size; ++i)
        {
            std::cout << (char)(65+i) << ' ';
        }
    }
    
    
private:
    size_t _size;
    Cell* _cells;
};

int main(void)
{
    Board* board8 = new Board(8);
    board8->Print();
    
    std::cout<<"\n\n\n";
    
     Board* board12 = new Board(12);
     board12->Print();
    
}
