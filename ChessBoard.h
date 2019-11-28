#ifndef CHESSBOARD
#define CHESSBOARD

#include<string>
#include"ChessField.hpp"

using namespace std;

class ChessBoard {
  
  Piece* board[8][8]; // insert constants here 
  bool white_turn;

  /*
   * Description: moves through board and removes all pieces
   * Input:       none
   * Output:      none
   */
  void clearBoard();

  /*
   * Description: sets up board, putting pieces in the initial correct positions
   *              and making them back/white 
   * Input:       none
   * Output:      none
   */
  void setUpBoard();


/*
* Helper functions
*/

  void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << '\n';
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << '\n';
}

/* internal helper function */
void print_row(const ChessField data[], int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<8; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]->piece) ? data[i]->piece->display : " ") << " ";
  }
  cout << "|" << '\n';
}

/* pre-supplied function to display a Sudoku board */
void display_board(ChessField[8][8]) {
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



  /*
   * Description: init sets up the board, calling functions to clear the
   *              existing board and then set it up in the correct starting 
   *              configuration
   * Input:       none
   * Output:      none
   */
  void init();

  /*
   *
   *
   */
  bool charPositionToIntPosition(char* char_pos, int& int_row_pos, int& int_col_pos);

  void killPiece(ChessField* field);

  bool kingInCheck(ChessField* source, ChessField* destination);

  bool checkStaleMate();

 public:
  ChessBoard();
  ~ChessBoard();
  
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

  bool canMakeMove(ChessField source_field, ChessField* destination_field);
  
}