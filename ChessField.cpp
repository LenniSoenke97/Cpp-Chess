#include"ChessField.hpp"
#include"Piece.hpp"

ChessField::ChessField(int row, int col, Piece* piece): 
  row(row), 
  col(col), 
  piece(piece)
{
  char_position[0] = (char)col + 'A';
  char_position[1] = (char)row + '1';
}

ChessField::~ChessField()
{
  if(piece) delete piece;
  return;
}
