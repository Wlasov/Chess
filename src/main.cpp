#include "Board.h"
#include <conio.h>

int main(void)
{	
	Board* b = new Board(8);
	b->PlacePiece("a1", new Pawn(Black));
	std::cout<<*b;
	b->MovePiece("a1", "d4");
	std::cout<<*b;
	
}