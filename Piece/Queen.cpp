#include"Queen.hpp"

virtual bool Queen::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/)
{
  if (canMoveDiagonal()) return true;
  if (canMoveVertical()) return true;
  if (isHorizontal()) return true;

  return false;
};
