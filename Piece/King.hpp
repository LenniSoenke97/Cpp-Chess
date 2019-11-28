#ifndef KING
#define KING

#include"../Piece.hpp"
#include"../ChessPiece.hpp"

class King : public Piece {

    bool max_distance = 1;
    
  public:
    King(bool isWhite):Piece::Piece(isWhite) {};
    bool override canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/);

    bool castling(ChessField* source, ChessField* destination);

#endif
