#include"Bishop.hpp"

bool override Bishop::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/)
{ 
  if (canMoveDiagonal(source, destination, board)) return true;

  return false;
};
