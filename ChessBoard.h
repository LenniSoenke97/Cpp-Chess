#ifndef CHESSBOARD
#define CHESSBOARD

#include<iostream> // delete
#include"Piece.hpp" // delete

#include<string>
#include"ChessField.hpp"

using namespace std; // delete

class ChessBoard
{
  
  ChessField* board[8][8]; // insert constants here 
  bool white_turn;

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
   * Description: converts the given character position in which moves are usually
   *              given into integers for row and column indexes (eg. "D2" goes to
   *              row = 1 and col = 3
   * Input:       char* char_pos: the given character positon (eg. "D2")
   *              int& int_row_pos: a parameter passed by reference that will be
   *              populated with the row index
   *              int& int_col_pos: a parameter passed by reference that will be
   *              populated with the column index
   * Output:      True is char_pos could be converted into row and col indexes
   *              False if there was an error converting the position
   */
  bool charPositionToIntPosition(const char* char_pos, int& int_row_pos, int& int_col_pos);

  /*
   * Description: loops through all enemy figures and checks whether any of them
   *              could kill the king
   * Input:       none
   * Output:      True if the players king is in check
   *              False if not
   */
  bool kingInCheck();

  /*
   * Description: loops through all figures of the player whose turn it is and then
   *              checks if they can move to any field on the chessboard.
   * Input:       none
   * Output:      True if no figure can make any valid moves
   *              False if a figure can move
   */
  bool noMovesPossible();

  /*
   * Description: will call various functions to validate whether the supplied
   *              move (source to destination) is a valid one
   * Input:       ChessField* source_field: the field the player wants to move the
   *              piece from.
   *              ChessField* destination_field: the field the players wants to move
   *              the piece to.
   * Output:      True if move is valid
   *              False if not
   */
  bool canMakeMove(ChessField* source_field, ChessField* destination_field);
  

 public:
  
  ChessBoard();
  ~ChessBoard();

  /*
   * Description: calls the clearBoard() and setupBoard() functions to remove all
   *              current pieces and fields from the board and then place new
   *              figures in the correct positions to start a new game.
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
   * Helper functions
   */

  void print_frame(int row) {
    if (!(row % 3))
      cout << "  +===========+===========+===========+" << '\n';
    else
      cout << "  +---+---+---+---+---+---+---+---+---+" << '\n';
  }

  void print_row(ChessField* data[], int row) {
    cout << (char) ('A' + row) << " ";
    for (int i=0; i<8; i++) {
      cout << ( (i % 3) ? ':' : '|' ) << " ";
      if (data[i]->piece) { }
      cout << ( (data[i]->piece) ? data[i]->piece->display : ' ') << " ";
    }
    cout << "|" << '\n';
  }

  void display_board() {
    cout << "    ";
    for (int r=0; r<8; r++) 
      cout << (char) ('1'+r) << "   ";
    cout << '\n';
    for (int r=0; r<8; r++) {
      print_frame(r);
      print_row(board[r],r);
    }
    print_frame(8);
  }






};

#endif
