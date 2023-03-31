#include "Board.h"

Board::Board() {}

Board::Board(size_t size): _size(size)
{
    _cells = new Cell[size*size];
    int currentCell = _size*size-1;

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

bool IsLetterCoordValid(const std::string& coordinate, size_t boardSize)
{
    return (int)(coordinate[0])-97 > 0 && (int)(coordinate[0])-97 < boardSize;
}

bool IsNumericCoorValid(const std::string& coordinate, size_t boardSize)
{
    return (int)(coordinate[1])-49 > 0 && (int)(coordinate[1])-49 < boardSize;
}

void Board::PlacePiece(const std::string& coordinate, Piece* piece)
{    
    size_t col = ColCoordinateToInt(coordinate);
    size_t row = _size - 1 - RowCoorinateToInt(coordinate);
    
    EColor tmpColor = _cells[_size*col+row].GetColor();
    Coordinate* tmpCoord = new Coordinate(col, row);
    _cells[_size*row+col] = Cell(tmpColor, tmpCoord, piece);
}

void Board::RemovePiece(const std::string& coordinate)
{
    size_t col = ColCoordinateToInt(coordinate);
    size_t row = _size - 1 - RowCoorinateToInt(coordinate);
    
    EColor tmpColor = _cells[_size*col+row].GetColor();
    Coordinate* tmpCoord = new Coordinate(col, row);
    _cells[_size*row+col] = Cell(tmpColor, tmpCoord);
}

void Board::MovePiece(const std::string& from, const std::string& to, EInputMode inputMode)
{
    size_t col = ColCoordinateToInt(from);
    size_t row = _size - 1 - RowCoorinateToInt(from);
    Piece* target = _cells[_size*row+col].GetPiece();
    
    PlacePiece(to, target);
    RemovePiece(from);
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