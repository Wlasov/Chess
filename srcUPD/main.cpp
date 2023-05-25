#include "ChessPiece.h"
#include "Game.h"
#include "ChessRules.h"

void FillBoardStandart(Board* b)
{
	for (int i = 0; i < 8; ++i)
	{
		b->PlacePiece(new Coordinate(1,i), new Pawn(White));
		b->PlacePiece(new Coordinate(6,i), new Pawn(Black));
	}

	b->PlacePiece(new Coordinate(0,0), new Rook(White));
	b->PlacePiece(new Coordinate(0,1), new Knight(White));
	b->PlacePiece(new Coordinate(0,2), new Bishop(White));
	b->PlacePiece(new Coordinate(0,3), new Queen(White));
	b->PlacePiece(new Coordinate(0,4), new King(White));
	b->PlacePiece(new Coordinate(0,5), new Bishop(White));
	b->PlacePiece(new Coordinate(0,6), new Knight(White));
	b->PlacePiece(new Coordinate(0,7), new Rook(White));

	b->PlacePiece(new Coordinate(7,7), new Rook(Black));
	b->PlacePiece(new Coordinate(7,6), new Knight(Black));
	b->PlacePiece(new Coordinate(7,5), new Bishop(Black));
	b->PlacePiece(new Coordinate(7,4), new Queen(Black));
	b->PlacePiece(new Coordinate(7,3), new King(Black));
	b->PlacePiece(new Coordinate(7,2), new Bishop(Black));
	b->PlacePiece(new Coordinate(7,1), new Knight(Black));
	b->PlacePiece(new Coordinate(7,0), new Rook(Black));
}

int main(void)
{
	#if defined(_WIN32)
		system("chcp 65001");
		system("cls");
	#endif
	
	
	Board* b = new Board(8);
	FillBoardStandart(b);
	std::cout<<*b;
	
	Game* game = new Game(EGameType::EightQueensProblem);
	game->Start();
}