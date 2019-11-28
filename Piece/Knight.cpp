#include"Knight.hpp"

bool override Knight::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/)
{
    int difference_row = abs(source->row - destination->row);
    int difference_col = abs(source->col - destination->col);
    if ((difference_col == 2 && difference_row == 1) || (difference_row == 2 && difference_col == 1)) {
        return true;
    }
  return false;
};
