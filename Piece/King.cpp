#include"King.hpp"

virtual bool King::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/)
  {
      if (!isWithinMaxDistance()) return false;
      if (canMoveDiagonal()) return true;
      if (canMoveDiagonal()) return true;
      if (isHorizontal()) return true;

      return false;
  };
