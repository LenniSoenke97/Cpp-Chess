#ifndef PIECE
#define PIECE

#include"ChessField.hpp"
#include<string>
#include"Global.h"

using namespace std;

class Piece
{
  
protected:

  bool has_moved = false;

  /*
   * Description: checks whether the source and destination fields
   *              are diagonal to each other and that there is
   *              no other figure between source and destination
   *              field
   * Input:       ChessField* source: the field you want to move a
   *              figure from
   *              ChessField* destination: the field you want to
   *              move the figure to
   *              ChessField* board[][]: the board the current game
   *              is being played on.
   * Output:      True if the destination field is diagonal from the
   *              source field and no figure is on the diagonal path
   *              between the two fields
   *              False otherwise
   */
  bool canMoveDiagonal(ChessField* source,
		       ChessField* destination,
		       ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]) const;

  /*
   * Description: checks whether the source and destination fields
   *              are horizontal to each other and that there is
   *              no other figure between source and destination
   *              field
   * Input:       ChessField* source: the field you want to move a
   *              figure from
   *              ChessField* destination: the field you want to
   *              move the figure to
   *              ChessField* board[][]: the board the current game
   *              is being played on.
   * Output:      True if the destination field is horizontal from the
   *              source field and no figure is on the diagonal path
   *              between the two fields
   *              False otherwise
   */
  bool canMoveHorizontal(ChessField* source,
			 ChessField* destination,
			 ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]) const;
  

  /*
   * Description: checks whether the source and destination fields
   *              are vertical to each other and that there is
   *              no other figure between source and destination
   *              field
   * Input:       ChessField* source: the field you want to move a
   *              figure from
   *              ChessField* destination: the field you want to
   *              move the figure to
   *              ChessField* board[][]: the board the current game
   *              is being played on.
   * Output:      True if the destination field is vertical from the
   *              source field and no figure is on the diagonal path
   *              between the two fields
   *              False otherwise
   */
  bool canMoveVertical(ChessField* source,
		       ChessField* destination,
		       ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]) const;

  /*
   * Description: checks whether the destination field is within the
   *              maximum allowed movable distance of the piece on the
   *              source field. Distance is defined as the maximum of
   *              row distance and column distance between source and
   *              destination. 
   * Input:       ChessField* source: the field you want to move a
   *              figure from
   *              ChessField* destination: the field you want to
   *              move the figure to
   *              int max_distance: the maximum distance the piece can move.
   * Output:      True if the destination field is within the maximum
   *              distance of the chess piece of the source field
   *              False otherwise
   */
  bool isWithinMaxDistance(ChessField* source,
			   ChessField* destination,
			   int max_distance) const;  
  
public:

  const bool is_white;

  /* Piece constructor
   * Description: sets the is_white attribute
   * Input:       bool is_white: boolean indicating whether the piece is white
   *              or not.
   */
  Piece(bool is_white) : is_white(is_white) {};

  /*
   * Description: canMakeMove determines whether it is within the rules of the game
   *              for a figure to make a move from the source field to the destination 
   *              field. The function only checks whether the destination field is within
   *              range and the path to the destination is one the piece on the source field
   *              can take and no pieces are in the way. It does not check anything else.
   *              Thos os a pure virtual function and must be implemented by derrived classes.
   * Input:       ChessField* source: the field you want to move a
   *              figure from
   *              ChessField* destination: the field you want to
   *              move the figure to
   *              ChessField* board[][]: the board the current game
   *              is being played on.
   * Output:      True if the destination field is within range and the path to the destination
   *              is allowed for the piece on the source field.
   *              False otherwise
   */
  virtual bool canMakeMove(ChessField* source,
			   ChessField* destination,
			   ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]) const = 0;

  /*
   * Description: sets the has_moved attribute to 1
   * Input:       none
   * Output:      void
   */
  virtual void hasMoved();

  /*
   * Description: accessor for the has_moved property
   * Input:       none
   * Output:      the has_moved value (boolean)
   */
  virtual bool getHasMoved() const;

  /*
   * Description: a pure virtual function for displaying the name of the given piece
   * Input:       none
   * Output:      char* the name of the piece
   */
  virtual char* display() const = 0;
  
  /*
   * Piece destructor
   */
  virtual ~Piece() {};

};

#endif
