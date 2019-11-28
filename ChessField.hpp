#ifndef CHESSFIELD
#define CHESSFIELD

class Piece;

struct ChessField {
  Piece* piece;
  int row; // make this constant, should not change
  int col; // make this constant should not change
  char char_position[2];
 ChessField(int row, int col, Piece* piece = nullptr);
};

#endif
