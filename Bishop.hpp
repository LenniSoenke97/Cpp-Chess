#ifndef BISHOP
#define BISHOP

#include"../Piece.hpp"
#include"../ChessField.hpp"

class Bishop : public Piece {

  bool max_distance = 1;
    
  public:

    Bishop(bool isWhite):Piece::Piece(isWhite) {
        display = 'B'; //delete this
    };
   bool canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) ;
        
};
#endif
