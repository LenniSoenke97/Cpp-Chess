#ifndef PAWN
#define PAWN

#include"Piece.hpp"
#include"ChessField.hpp"

class Pawn : public Piece {

protected:
    bool max_distance = 2;

private:

bool canKillDiagonal(ChessField* source, ChessField* destination);

  public:
    Pawn(bool isWhite):Piece::Piece(isWhite) {
        display = 'P'; //delete this
    };
  bool canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) /*override*/;
    
    void hasMoved() override;

};
#endif
