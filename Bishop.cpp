#include"Bishop.hpp"

bool Bishop::canMakeMove(ChessField* source, 
			 ChessField* destination, 
			 ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]) const
{ 
  if (canMoveDiagonal(source, destination, board)) return true;  
  return false;
}

char* Bishop::display() const {
  return (char*) "Bishop";
}
