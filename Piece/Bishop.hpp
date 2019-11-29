#ifndef BISHOP
#define BISHOP

#include"../Piece.hpp"
#include"../ChessField.hpp"

class Bishop : public Piece {

  bool max_distance = 1;
    
  public:

  char display() override { return 'B'; };
    Bishop(bool isWhite):Piece::Piece(isWhite) {};
   bool canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) ;
        
};
#endif
