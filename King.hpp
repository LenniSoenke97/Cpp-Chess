#ifndef KING
#define KING

#include"Piece.hpp"
#include"ChessField.hpp"

class King : public Piece
{

  int king_max_distance = 1;
    
public:

  /*
   * King Constructor
   * Description: constructor of king, sets the colour of king and calls parent
   *              class constructor. The constructor also sets the kings max
   *              moving distance to 1.
   * Input:       bool isWhite: boolean indicating whether it is a white piece
   */
  King(bool isWhite):Piece::Piece(isWhite) {};
  /*
   * Description: canMakeMove returns whether a king on a certain source field 
   *              can make a move to a given destination field. The function 
   *              checks whether the destination field is diagonal, horizontal 
   *              or vertical from the source field, is max 1 field away and 
   *              that no other figures are in the way.
   * Input:       ChessField* source: the chess field that the king you want to 
   *              move is on
   *              ChessField* destination: the chess field you want to move the
   *              king to
   *              ChessField* board[][]: the current board of chessfields the 
   *              game is being
   *              played on
   * Output:      True if move is valid
   *              False if move is invalid
   */
  bool  canMakeMove(ChessField* source, 
		    ChessField* destination, 
		    ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]) const override;

  /* 
   * Description: returns the name of the piece
   * Input:       none
   * Output:      char* name of the piece
   */
  char* display() const override;

};

#endif
