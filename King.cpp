#include"King.hpp"
#include"Rook.hpp" // delete

bool  King::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]) const
{
  if (!isWithinMaxDistance(source, destination, king_max_distance)) return false;
  if (canMoveDiagonal(source, destination, board)) return true;
  if (canMoveVertical(source, destination, board)) return true;
  if (canMoveHorizontal(source, destination, board)) return true;

  return false;
}

char* King::display() const {
  return (char*) "King";
}
