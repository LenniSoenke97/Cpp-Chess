#ifndef CHESSFIELD
#define CHESSFIELD

class Piece;

struct ChessField
{
  const int row;
  const int col;
  Piece* piece;
  char char_position[2];

  /*
   * ChessField constructor
   * Description: sets the row, column and initial piece on the
   *              chess field, as well as the char_position.
   * Input:       int row: the row index of the field
   *              int col: the col index of the field
   *              Piece* piece: the initial piece on the field
   *              (nullptr, ie. empty field, by default)
   */
  ChessField(const int row, const int col, Piece* piece = nullptr);

  /*
   * ChessField destructor
   * Description: delete the ChessField piece if one has been created
   */
  ~ChessField();
};

#endif
