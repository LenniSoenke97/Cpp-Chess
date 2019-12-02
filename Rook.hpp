#ifndef ROOK
#define ROOK

#include"Piece.hpp"
#include"ChessField.hpp"

class Rook : public Piece
{
    
public:

  /*
   * Rook Constructor
   * Description: constructor of rook, sets the colour of rook and calls parent
   *              class constructor
   * Input:       bool isWhite: boolean indicating whether it is a white piece
   */
  Rook(bool isWhite):Piece::Piece(isWhite)
  { 
    display = 'R'; //delete this
  };

  /*
   * Description: canMakeMove returns whether a rook on a certain source field can make
   *              a move to a given destination field. The function checks whether the 
   *              destination field is horizontal or vertical from the source field and 
   *              that no other figures are in the way.
   * Input:       ChessField* source: the chess field that the rook you want to move is on
   *              ChessField* destination: the chess field you want to move the rook to
   *              ChessField* board[][]: the current board of chessfields the game is being
   *              played on
   * Output:      True if move is valid
   *              False if move is invalid
   */
  bool  canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) const override;
        
};

#endif
