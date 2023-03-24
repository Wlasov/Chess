#include "Functions.h"

std::string ColorToString(EColor color)
{
	switch (color)
    {
        case 0:
            return "\u25A0 ";
        case 1:
            return  "\u25A1 ";
        default:
            return "  ";
    }
}