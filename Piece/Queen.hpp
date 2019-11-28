#ifndef QUEEN
#define QUEEN

#include"../ChessField.hpp";
#include"Piece.hpp"

class Queen : public Piece {

  public:
    Queen(bool isWhite):Piece::Piece(isWhite) {};
  virtual bool canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/);
    
  
}

#endif
