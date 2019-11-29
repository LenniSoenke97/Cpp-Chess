#ifndef PAWN
#define PAWN

#include"../Piece.hpp"
#include"../ChessField.hpp"

class Pawn : public Piece {

protected:
    bool max_distance = 2;

private:
  char display() override { return 'P'; };
bool canKillDiagonal(ChessField* source, ChessField* destination);

  public:
    Pawn(bool isWhite):Piece::Piece(isWhite) {};
  bool  canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) override;
    
    void hasMoved() override;

};
#endif
