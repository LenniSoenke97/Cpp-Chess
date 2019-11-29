#ifndef KING
#define KING

#include"Piece.hpp"
#include"ChessField.hpp"

class King : public Piece {

    
  public:


    King(bool isWhite):Piece::Piece(isWhite) {
      max_distance = 1;
        display = 'K'; //delete this
    };
    bool  canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) override;

  bool castling(ChessField* source, ChessField* destination, ChessField* board[8][8]);

};
#endif
