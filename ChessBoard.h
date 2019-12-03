#ifndef CHESSBOARD
#define CHESSBOARD

#include"Global.h"
#include"ChessField.hpp"

class ChessBoard
{

  ChessField* board[NUM_OF_ROWS][NUM_OF_COLS];
  bool white_turn;
  bool game_over = true;
  bool virtual_move = false;

  /*
   * Description: iterates through board and removes all pieces
   * Input:       none
   * Output:      none
   */
  void clearBoard();

  /*
   * Description: sets up board, clearing all current fields and
   *              putting pieces in the initial correct positions
   *              and making them back/white 
   * Input:       none
   * Output:      none
   */
  void setupBoard();

  /*
   * Description: converts the given character position in which moves are 
   *              usually given into integers for row and column indexes (eg. 
   *              "D2" goes to row = 1 and col = 3
   * Input:       char* char_pos: the given character positon (eg. "D2")
   *              int& int_row_pos: a parameter passed by reference that will
   *              be populated with the row index
   *              int& int_col_pos: a parameter passed by reference that will
   *              be populated with the column index
   * Output:      True is char_pos could be converted into row and col indexes
   *              False if there was an error converting the position
   */
  bool charPositionToIntPosition(const char* char_pos, 
				 int& int_row_pos, 
				 int& int_col_pos);

  /*
   * Description: loops through all enemy figures and checks whether any of
   *              them could kill the king
   * Input:       none
   * Output:      True if the players king is in check
   *              False if not
   */
  bool kingInCheck();

  /*
   * Description: loops through all figures of the player whose turn it is and 
   *              then checks if they can move to any field on the chessboard.
   * Input:       none
   * Output:      True if no figure can make any valid moves
   *              False if a figure can move
   */
  bool noMovesPossible();
  
  /*
   * Description: will execute the proposed move if the move is not a virtual
   *              move and will then check and return whether the player making 
   *              the move is in check, after rolling back the move. 
   * Input:       ChessField* source_field: the field the player wants to move 
   *              the piece from.
   *              ChessField* destination_field: the field the players wants
   *              to move the piece to.
   * Output:      True if move results in check for the player
   *              False if not
   */
  bool inCheckAfterMove(ChessField* source_field, 
    ChessField* destination_field);

  /* 
   * Description: checks if there is actual movement from source_field to 
   *              destination_field since pieces cannot stay on same field.
   * Input:       ChessField* source_field: the field the player wants to move
   *              the piece from.
   *              ChessField* destination_field: the field the players wants
   *              to move the piece to.
   * Output:      True if movement occurs
   *              False if not
   */
  bool isMovement(ChessField* source_field, ChessField* destination_field) 
    const;

  /* 
   * Description: checks if there is actual movement from source_field to 
   *              destination_field since pieces cannot stay on same field.
   * Input:       ChessField* source_field: the field the player wants to move
   *              the piece from.
   *              ChessField* destination_field: the field the players wants
   *              to move the piece to.
   * Output:      True if movement occurs
   *              False if not
   */
  bool isMovement(ChessField* source_field, ChessField* destination_field) 
    const;

  /* 
   * Description: checks that there is a piece on the source_field
   * Input:       ChessField* source_field: the field the player wants to move
   *              the piece from.
   * Output:      True if there is a piece on the source_field
   *              False if not
   */
  bool isFieldWithPiece(ChessField* source_field) const;

  /* 
   * Description: checks if the piece that is being moved belongs to the
   *              player whose turn it is.
   * Input:       ChessField* source_field: the field the player wants to move
   *              the piece from.
   * Output:      True if current player is moving a piece of his own colour
   *              False if not
   */
  bool isPlayer(ChessField* source_field) const;

  /* 
   * Description: checks whether the destination field has a friendly piece on
   *              it
   * Input:       ChessField* source_field: the field the player wants to move
   *              the piece from.
   *              ChessField* destination_field: the field the players wants
   *              to move the piece to.
   * Output:      True if destination has friendly piece
   *              False if not
   */
  bool destinationFieldIsFriendly(ChessField* source_field, 
				  ChessField* destination_field) const;

  /* 
   * Description: prints out any movement errors
   * Input:       ChessField* source_field: the field the player wants to move
   *              the piece from.
   *              ChessField* destination_field: the field the players wants
   *              to move the piece to.
   * Output:      void
   */
  void printMovementError(ChessField* source_field, 
			  ChessField* destination_field) const;

  /* 
   * Description: prints out any movement
   * Input:       ChessField* source_field: the field the player wants to move
   *              the piece from.
   *              ChessField* destination_field: the field the players wants
   *              to move the piece to.
   * Output:      void
   */
  void printMovement(ChessField* source_field, 
		     ChessField* destination_field, 
		     bool kill) const;

  /* 
   * Description: prints out game result and set game_over to true if game has
   *              ended the game result options are: player is in check,
   *              player is in checkmate, stalemate or nothing.
   * Input:       bool king_in_check: boolean indicating whether king is in
   *              check
   *              bool no_moves_possible: boolean indicating whether the
   *              player has no possible moves
   * Output:      void
   */
  void handleGameResult(const bool king_in_check, 
			const bool no_moves_possible);

  /* 
   * Description: checks if the supplied move is a castling move and executes
   *              the move if yes.
   * Input:       ChessField* source_field: the field the player wants to move
   *              the piece from.
   *              ChessField* destination_field: the field the players wants
   *              to move the piece to.
   * Output:      True if the move is a castling move
   *              False if not
   */
  bool isCastling(ChessField* source_field, ChessField* destination_field);

 public:

  /*
   * Chessboard constructor
   * Description: sets up new game automatically
   * Input:       none
   */
  ChessBoard();
  
  /*
   * Description: calls the clearBoard() and setupBoard() functions to remove
   *              all current pieces and fields from the board and then place
   *              new figures in the correct positions to start a new game.
   * Input:       none
   * Output:      none
   */
  void resetBoard();

  
  /*
   * Description: function that takes the source and destination position of
   *              a move a player wants to make, the function then verifies 
   *              whether this move is possible and executes the move if yes.
   * Input:       Source - the starting position of the piece the player wants
   *              wants to move.
   *              Destination - the position the player wants to move the piece
   *              to. 
   * Output:      void
   */
  void submitMove(const char* source, const char* destination);

  /*
   * ChessBoard destructor
   * Description: loops through board and delete all ChessFields
   */
  ~ChessBoard();

};

#endif
