#include"Bishop.hpp"

bool Bishop::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) const
{ 
  if (canMoveDiagonal(source, destination, board)) return true;  
  return false;
}
