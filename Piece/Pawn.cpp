#include"Pawn.hpp"

bool override Pawn::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/)
{

    if (canKillDiagonal(source, destination, board)) return true;
    int difference_row = abs(source->row - destination->row);
    int difference_col = abs(source->col - destination->col);
    if (distance_col != 0) return false;
    // checking if pawn is moving rihgt awy
    if (difference_row*this->is_white < 0) return false;
  if (!isWithinMaxDistance(source, destination)) return false;
  if (canMoveVertical(source, destination, board)) return true;

  return false;
};

void Pawn::hasMoved() {
    has_moved = 1;
    max_distance = 1;
}

bool Pawn::canKillDiagonal(ChessField* source, ChessField* destination) {
    // is field diagonal?
    int difference_row = abs(source->row - destination->row);
    int difference_col = abs(source->col - destination->col);
    if (difference_col != 1 || difference_row != 1) return false;

    // is there an enemy on the field
    if(destination->piece) {
        if (destination->piece->isWhite() != this->isWhite()) return true
    }

    return false
}