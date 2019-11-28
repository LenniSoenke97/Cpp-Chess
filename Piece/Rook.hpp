#ifndef ROOK
#define ROOK

#include"../Piece.hpp"
#include"../ChessPiece.hpp"

class Rook : public Piece {

    bool max_distance = 1;
    
  public:
    Rook(bool isWhite):Piece::Piece(isWhite) {};
  bool override canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/);
        

#endif