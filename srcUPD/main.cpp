#include "ChessPiece.h"
#include "Game.h"


int main(void)
{
	Queens* qs = new Queens(8);
	qs->FindAllSolutions(0);
	qs->PrintAllSolutions();
}