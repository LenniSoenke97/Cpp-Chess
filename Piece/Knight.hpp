#ifndef KNIGHT
#define KNIGHT

#include"../Piece.hpp"
#include"../ChessField.hpp"

class Knight : public Piece {

    bool max_distance = 1;
    
  public:
    Knight(bool isWhite):Piece::Piece(isWhite) {};
  bool override canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/);
        

#endif