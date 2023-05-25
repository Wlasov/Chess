#pragma once
#include "Board.h"

// Interface of game type
class IGameRules
{
public:
	virtual void MovePiece(const std::string& from, const std::string& to) = 0; // move piece from "from" to "to".
};
