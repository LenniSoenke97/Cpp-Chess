#ifndef PIECE
#define PIECE

#include"ChessField.hpp"


class Piece {
protected:

  bool has_moved = false;
  bool max_distance = 8; // get this from constant

  bool canMoveDiagonal(ChessField* source,
		  ChessField* destination,
		  ChessField* board[8][8]);

  bool canMoveHorizontal(ChessField* source,
		    ChessField* destination,
		    ChessField* board[8][8]);
  

   bool canMoveVertical(ChessField* source,
		  ChessField* destination,
		  ChessField* board[8][8]);

  bool isWithinMaxDistance(ChessField* source,
			   ChessField* destination);  
  
public:

  char display = 'T'; ///// delete this

  
  const bool is_white;

  Piece(bool is_white):is_white(is_white) {};

  // make this function friendly to board????
  // note this function is a "pure virtual function", ie. it is not implemented here, must be implemented by derived classes
  virtual bool canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) = 0;
    
  virtual void hasMoved();
  virtual bool getHasMoved();

  ~Piece() {};
};

#endif
