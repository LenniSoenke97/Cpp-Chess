#ifndef ROOK
#define ROOK

#include"../Piece.hpp"
#include"../ChessField.hpp"

class Rook : public Piece {
  
    bool max_distance = 1;
    
  public:

  char display() override { return 'R'; };

  Rook(bool isWhite):Piece::Piece(isWhite) {};
  bool  canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) override;
        
};

#endif
