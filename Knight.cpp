#include <cstdlib>
#include"Knight.hpp"

bool  Knight::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]) const
{
  int difference_row = abs(source->row - destination->row);
  int difference_col = abs(source->col - destination->col);
  if ((difference_col == 2 && difference_row == 1) || (difference_row == 2 && difference_col == 1)) {
    return true;
  }
  return false;
}

char* Knight::display() const {
  return (char*) "Knight";
}
