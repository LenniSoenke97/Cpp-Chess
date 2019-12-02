#ifndef QUEEN
#define QUEEN

#include"Piece.hpp"
#include"ChessField.hpp"

class Queen : public Piece
{
    
public:

  /*
   * Queen Constructor
   * Description: constructor of queen, sets the colour of queen and calls parent
   *              class constructor
   * Input:       bool isWhite: boolean indicating whether it is a white piece
   */
  Queen(bool isWhite):Piece::Piece(isWhite)
  {
    display = "Queen"; //delete this
  };

  /*
   * Description: canMakeMove returns whether a queen on a certain source field can make
   *              a move to a given destination field. The function checks whether the 
   *              destination field is diagonal, horizontal or vertical from the source 
   *              field and that no other figures are in the way.
   * Input:       ChessField* source: the chess field that the queen you want to move is on
   *              ChessField* destination: the chess field you want to move the queen to
   *              ChessField* board[][]: the current board of chessfields the game is being
   *              played on
   * Output:      True if move is valid
   *              False if move is invalid
   */
  bool  canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) const override;
        
};

#endif
