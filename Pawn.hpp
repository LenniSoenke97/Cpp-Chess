#ifndef PAWN
#define PAWN

#include"Piece.hpp"
#include"ChessField.hpp"

class Pawn : public Piece
{

  int pawn_max_distance = 2;
  
private:
  
  /*
   * Description: this function checks whether the provided destination field
   *              is diagonal from the source field, within a distance of 1 and 
   *              an enemy figure is on the field.
   * Input:       ChessField* source: the chess field that the pawn you want to move is on
   *              ChessField* destination: the chess field you want to move the pawn to
   * Output:      True if move is valid
   *              False if move is invalid
   */
  bool canKillDiagonal(ChessField* source, ChessField* destination) const;

public:

  /*
   * Pawn Constructor
   * Description: constructor of pawn, sets the colour of pawn and calls parent
   *              class constructor
   * Input:       bool isWhite: boolean indicating whether it is a white piece
   */
  Pawn(bool isWhite):Piece::Piece(isWhite)
  {
    display = 'P'; //delete this
  };

  /*
   * Description: canMakeMove returns whether a pawn on a certain source field can make
   *              a move to a given destination field. The function checks whether the 
   *              destination field is within moving distance from the source field, that
   *              no other figures are in the way, the destination field is straight ahead
   *              of the pawn or the field is diagonal from the pawn and an enemy figure
   *              is on this field.
   * Input:       ChessField* source: the chess field that the pawn you want to move is on
   *              ChessField* destination: the chess field you want to move the pawn to
   *              ChessField* board[][]: the current board of chessfields the game is being
   *              played on
   * Output:      True if move is valid
   *              False if move is invalid
   */
  bool canMakeMove(ChessField* source, ChessField* destination, ChessField* board[8][8] /*make these to const*/) const override;

  /*
   * Description: this function marks sets the pawn's has_moved attribute to true and changes
   *              the maximum movable distance to 1 (since only pawns who have not moved yet
   *              can move two fields forward)
   * Input:       none
   * Output:      void
   */
  void hasMoved() override;

};
#endif
