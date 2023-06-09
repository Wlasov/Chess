#pragma once
#include "BasePiece.h"
#include "Signs.h"

/*
	Classes of the Chess pieces.
*/

class Pawn: public BasePiece
{
public:
	Pawn(EColor color): BasePiece(color, color ? BLACK_PAWN_SIGN : WHITE_PAWN_SIGN, PW) {};
	~Pawn() {};
	
	bool GetMovedState()
	{
		return _hasMoved;
	}
	
	// chage while pawn's move
	void ChangeMovedState()
	{
		_hasMoved = true;
	}
	
private:
	bool _hasMoved = false; // a flag that indicates whether the pawn has made a move. If it doesn't, it can move 2 cells forward; if not, it can move 1 cell.
};

class Queen: public BasePiece
{
public:
	Queen(EColor color): BasePiece(color, color ? BLACK_QUEEN_SIGN : WHITE_QUEEN_SIGN, QN) {};
	~Queen() {};
};

class King: public BasePiece
{
public:
	King(EColor color): BasePiece(color, color ? BLACK_KING_SIGN : WHITE_KING_SIGN, NoType) {};
	~King() {};
};

class Rook: public BasePiece
{
public:
	Rook(EColor color): BasePiece(color, color ? BLACK_ROOK_SIGN : WHITE_ROOK_SIGN, NoType) {};
	~Rook() {};
};

class Bishop: public BasePiece
{
public:
	Bishop(EColor color): BasePiece(color, color ? BLACK_BISHOP_SIGN : WHITE_BISHOP_SIGN, NoType) {};
	~Bishop() {};
};

class Knight: public BasePiece
{
public:
	Knight(EColor color): BasePiece(color, color ? BLACK_KNIGHT_SIGN : WHITE_KNIGHT_SIGN, NoType) {};
	~Knight() {};
};
