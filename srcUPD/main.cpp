#include "ChessPiece.h"
#include "Game.h"
#include "ChessRules.h"

int main(void)
{
	#if defined(_WIN32)
		system("chcp 65001");
	#endif
	
	Queens* qs = new Queens(4);
	qs->FindAllSolutions(0);
}