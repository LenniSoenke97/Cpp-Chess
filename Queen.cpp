#include"Queen.hpp"

bool Queen::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]
) const
{
  if (canMoveDiagonal(source, destination, board)) return true;
  if (canMoveVertical(source, destination, board)) return true;
  if (canMoveHorizontal(source, destination, board)) return true;

  return false;
}

char* Queen::display() const {
  return "Queen";
}
