#pragma once
#include "Board.h"

class IGameRules
{
public:
	virtual void MovePiece(const std::string& from, const std::string& to) = 0;
};