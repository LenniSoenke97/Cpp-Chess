#ifndef KNIGHT
#define KNIGHT

#include"Piece.hpp"
#include"ChessField.hpp"

class Knight : public Piece
{

public:

  /*
   * Knight Constructor
   * Description: constructor of knight, sets the colour of knight and calls parent
   *              class constructor
   * Input:       bool isWhite: boolean indicating whether it is a white piece
   */
  Knight(bool isWhite):Piece::Piece(isWhite)
  {
    display = 'k'; //delete this
  };

  /*
   * Description: canMakeMove returns whether a knight on a certain source field can make
   *              a move to a given destination field. 
   * Input:       ChessField* source: the chess field that the knight you want to move is on
   *              ChessField* destination: the chess field you want to move the knight to
   *              ChessField* board[][]: the current board of chessfields the game is being
   *              played on
   * Output:      True if move is valid
   *              False if move is invalid
   */
  bool  canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) const override;
        
};

#endif
