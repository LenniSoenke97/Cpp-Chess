#include <cstdlib>
#include"Pawn.hpp"

bool Pawn::canKillDiagonal(ChessField* source, ChessField* destination) const
{
  int difference_row = abs(source->row - destination->row);
  int difference_col = abs(source->col - destination->col);
  if (difference_col != 1 || difference_row != 1) return false;

  if(destination->piece) {
    if (destination->piece->is_white != this->is_white) return true;
  }

  return false;
}

bool Pawn::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) const
{

  if (canKillDiagonal(source, destination)) return true;
  int difference_row = abs(source->row - destination->row);
  int difference_col = abs(source->col - destination->col);
  if (difference_col != 0) return false;
  if (difference_row*this->is_white < 0) return false;
  if (destination->piece) return false;
  if (!isWithinMaxDistance(source, destination, pawn_max_distance)) return false;
  if (canMoveVertical(source, destination, board)) return true;

  return false;
};

void Pawn::hasMoved()
{
  has_moved = true;
  pawn_max_distance = 2;
}


