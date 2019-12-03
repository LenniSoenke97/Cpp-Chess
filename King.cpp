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

bool King::castling(ChessField* source, ChessField* destination, ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]) const
{
  // completely wrong
  
  Piece* dest_piece = destination->piece;
  if (!(Rook*) dest_piece) return false;
  if (this->getHasMoved()) return false;
  if (dest_piece->getHasMoved()) return false;
  if (this->is_white != dest_piece->is_white) return false;
  if (source->row != destination->row) return false;

  ChessField* current_field;
  int row_change = (source->row > destination->row) ? -1 : 1;
  int current_row = source->row+row_change;
  while(current_row != destination->row) {
    current_field = board[current_row][source->col];
    if(current_field->piece) {
      return false;
    }
  }
    
  return true;
}

char* King::display() const {
  return "King";
}
