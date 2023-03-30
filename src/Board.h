#pragma once
#include <iostream>
#include "Cell.h"
#include "Coordinate.h"
#include "Color.h"
#include <typeinfo>

class Pawn: public Piece
{
public:
	Pawn();
	Pawn(EColor color): Piece(color, color ? "\u2659 " : "\u265F") {}
};

enum EInputMode
{
	PlayerInput,
	EnemyInput
};

class Board
{
public:
	Board();
	Board(size_t size);
	friend std::ostream& operator << (std::ostream& os, const Board& board);
	const size_t& GetSize();
	void PlacePiece(const std::string& coordinate, Piece* piece);
	void MovePiece(const std::string& from, const std::string& to, EInputMode inputMode);
	void RemovePiece(std::string& coordinate, Piece& piece);
	void DebugPrint();
	~Board();
	
private:
	size_t _size;
	Cell* _cells;
};