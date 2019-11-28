#ifndef BISHOP
#define BISHOP

#include"Piece.hpp"
#include"../ChessPiece.hpp"

class Bishop : public Piece {

    bool max_distance = 1;
    
  public:
    Bishop(bool isWhite):Piece::Piece(isWhite) {};
  virtual bool canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/);
        

#endif