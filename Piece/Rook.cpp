#include"Rook.hpp"

bool override Rook::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/)
{ 
  if (canMoveVertical(source, destination, board)) return true;
  if (canMoveHorizontal(source, destination, board)) return true;

  return false;
};

