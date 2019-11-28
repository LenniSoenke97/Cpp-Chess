#include"King.hpp"

bool  King::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/)
{
    // special case for the rook and king switch
  if (!isWithinMaxDistance(source, destination)) return false;
  if (canMoveDiagonal(source, destination, board)) return true;
  if (canMoveVertical(source, destination, board)) return true;
  if (isHorizontal(source, destination, board)) return true;

  return false;
};

bool King::castling(ChessField* source, ChessField* destination) {

    Piece* dest_piece = destination->piece;
    if (!(Rook*) dest_piece) return false;
    if (this->has_moved) return false;
    if (dest_piece->has_moved) return false;
    if (this->is_white != dest_piece->is_white) return false;
    if (source->row != destination->row) return false;

    ChessField* current_field;
    int row_change = (source->row > destination->row) ? -1 : 1;
    int current_row = source->row+row_change;
    while(current_row != destination->row) {
      current_field = board[current_row][source->col];
      if(current_field->piece) {
        return false;
      };
  }
    
    return true;
}