#ifndef QUEEN
#define QUEEN

#include"../Piece.hpp"
#include"../ChessField.hpp"

class Queen : public Piece {

    bool max_distance = 1;
    
  public:

  char display() override { return 'Q'; };
  
    Queen(bool isWhite):Piece::Piece(isWhite) {};
  bool  canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) override;
        
};

#endif
