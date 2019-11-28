// Rook.cpp

virtual bool Rook::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/)
{ 
  if (canMoveVertical()) return true;
  if (canMoveHorizontal()) return true;

  return false;
};

