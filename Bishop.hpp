#ifndef BISHOP
#define BISHOP

#include"Piece.hpp"
#include"ChessField.hpp"

class Bishop : public Piece
{
  
public:

  /*
   * Bishop Constructor
   * Description: constructor of bishop, sets the colour of bishop and calls 
   *              parent class constructor
   * Input:       bool isWhite: boolean indicating whether it is a white piece
   */
  Bishop(bool isWhite):Piece::Piece(isWhite) {};

  /*
   * Description: canMakeMove returns whether a bishop on a certain source 
   *              field can make a move to a given destination field. The 
   *              function checks whether the  destination field is diagonal 
   *              from the source field and that no other figures are in the 
   *              way.
   * Input:       ChessField* source: the chess field that the bishop you want 
   *              to move is on
   *              ChessField* destination: the chess field you want to move 
   *              the bishop to
   *              ChessField* board[][]: the current board of chessfields the
   *              game is being played on
   * Output:      True if move is valid
   *              False if move is invalid
   */
  bool canMakeMove(ChessField* source, 
		   ChessField* destination, 
		   ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]
		   ) const override;

  /* 
   * Description: returns the name of the piece
   * Input:       none
   * Output:      char* name of the piece
   */
  char* display() const override;

};
#endif
