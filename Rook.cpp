#include"Rook.hpp"

bool  Rook::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]
) const
{
  if (canMoveVertical(source, destination, board)) return true;
  if (canMoveHorizontal(source, destination, board)) return true;

  return false;
}

char* Rook::display() const {
  return (char*) "Rook";
}
