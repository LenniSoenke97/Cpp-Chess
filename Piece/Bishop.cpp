// Bishop.cpp

virtual bool Bishop::canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/)
{ 
  if (canMoveDiagonal()) return true;

  return false;
};
