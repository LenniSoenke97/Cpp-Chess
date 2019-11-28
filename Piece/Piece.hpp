#ifndef PIECE
#define PIECE

#include"../ChessField.hpp"

class Piece {
protected:

  char display = "T"; ///// delete this
  
  bool has_moved = false;
  bool max_distance = 8; // get this from constant

  bool isDiagonal(ChessField* source,
		  ChessField* destination,
		  ChessField* board[8][8]);

  bool isHorizontal(ChessField* source,
		    ChessField* destination,
		    ChessField* board[8][8]);
  

   bool isVertical(ChessField* source,
		  ChessField* destination,
		  ChessField* board[8][8]);

  bool isWithinMaxDistance(ChessField* source,
			   ChessField* destination);  
  
public:
  const bool is_white;

  Piece(bool isWhite):isWhite(isWhite) {};

  // make this function friendly to board????
  // note this function is a "pure virtual function", ie. it is not implemented here, must be implemented by derived classes
  virtual bool canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/);
  
  virtual void hasMoved();
}

#endif
