#pragma once
#include "Board.h"

class Player;

class GameMenager()
{
public:
    virtual void Start() = 0; // start game
    virtual void End() = 0; // end game
    virtual void Surrender(Player* sender) = 0; // surrent the game
    virtual void MakeMove(Player* sender) = 0; // make a move on the board
    virtual void OnBoardDraw() = 0; // Draw board in console
	
private:
    Board* _gameBoard;
    Piece* _whitePieces;
    Piece* _blackPieces;
	
    Player* _player;
    Player* _enemyPlayer;
}
