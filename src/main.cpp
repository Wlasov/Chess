#include "Board.h"
#include <conio.h>

bool IsInputValid(const std::string& input)
{
	if (input.size() != 2)
	{
		std::cout<<"not valid";
		return false;
	}
	
	if ((int)input[0]-97 < 0 || (int)input[0]-97 > 7)
	{
		std::cout<<"not valid";
		return false;
	}
	
	if ((int)input[1]-49 < 0 || (int)input[1]-49 > 7)
	{
		std::cout<<"not valid";
		return false;
	}
	
	return true;
}

void Game()
{
	Board* b = new Board(8);
	b->PlacePiece("e4", new Pawn(White));
	std::cout<<*b;
	
	std::string playerInputFrom;
	std::string playerInputTo;
	
	std::cout << "Input current Pos: ";
	std::cin >> playerInputFrom;
	
	if (!IsInputValid(playerInputFrom))
		Game();
	
	std::cout << "Input next Pos: ";
	std::cin >> playerInputTo;
	
	if (!IsInputValid(playerInputTo))
		Game();
	
	system("cls");
	Game();
}

int main(void)
{	

	Game();
}