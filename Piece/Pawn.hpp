#ifndef PAWN
#define PAWN

#include"Piece.hpp"
#include"../ChessPiece.hpp"

class Pawn : public Piece {

protected:
    bool max_distance = 2;

private:
    
bool canKillDiagonal(ChessField* source, ChessField* destination);

  public:
    Pawn(bool isWhite):Piece::Piece(isWhite) {};
  virtual bool canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/);
    
    virtual void hasMoved();
    
#endif