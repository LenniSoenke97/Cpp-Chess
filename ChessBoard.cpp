#include"ChessBoard.h"
#include"Rook.hpp"
#include"Knight.hpp"
#include"Bishop.hpp"
#include"Queen.hpp"
#include"King.hpp"
#include"Pawn.hpp"

using namespace std;

void ChessBoard::clearBoard() {
  for (int row = 0; row < 8 /* make this into constant*/; row++) {
      for (int col = 0; col < 8 /* make this into constant */; col++) {
	if(board[row][col]->piece) delete board[row][col]->piece;
	delete board[row][col];
      }
    } 
  };

void ChessBoard::setUpBoard() {
    bool isWhite = false;
    board[0][0] = new ChessField(0, 0, new Rook(isWhite));
    board[0][1] = new ChessField(0, 1, new Knight(isWhite));
    board[0][2] = new ChessField(0, 2, new Bishop(isWhite));
    board[0][3] = new ChessField(0, 3, new Queen(isWhite));
    board[0][4] = new ChessField(0, 4, new King(isWhite));
    board[0][5] = new ChessField(0, 5, new Bishop(isWhite));
    board[0][6] = new ChessField(0, 6, new Knight(isWhite));
    board[0][7] = new ChessField(0, 7, new Rook(isWhite));
    for (int col = 0; col < 8 /* make this into constant*/; col++) {
      board[1][col] = new ChessField(1, col, new Pawn(isWhite));
    }

    for (int row = 2; row < 6; row++) {
      for (int col = 0; col < 8 /* make this into constant */; col++) {
    board[row][col] = new ChessField(row, col);
      }
    }

    isWhite = true;
    board[7][0] = new ChessField(7, 0, new Rook(isWhite));
    board[7][1] = new ChessField(7, 1, new Knight(isWhite));
    board[7][2] = new ChessField(7, 2, new Bishop(isWhite));
    board[7][3] = new ChessField(7, 3, new Queen(isWhite));
    board[7][4] = new ChessField(7, 4, new King(isWhite));
    board[7][5] = new ChessField(7, 5, new Bishop(isWhite));
    board[7][6] = new ChessField(7, 6, new Knight(isWhite));
    board[7][7] = new ChessField(7, 7, new Rook(isWhite));
    for (int col = 0; col < 8 /* make this into constant*/; col++) {
      board[6][col] = new ChessField(6, col, new Pawn(isWhite));
    }
    
    white_turn = true;
  }

void ChessBoard::resetBoard() {
    clearBoard();
      setUpBoard();
  }

  bool ChessBoard::charPositionToIntPosition(const char* char_pos, int& int_row_pos, int& int_col_pos) {
    char char_col_pos = char_pos[0];
    char char_row_pos = char_pos[1];
    int_row_pos = (int)char_row_pos - (int)'1';
    int_col_pos = (int)char_col_pos - (int)'A';
    if (int_col_pos < 0 || int_row_pos < 0 || int_col_pos >= 8 || int_col_pos >= 8) { // make these values into constants
      //fprintf(stderr, "The following position %s is invalid.", char_pos);
      return false;
    }
    return true;
  }

  void ChessBoard::killPiece(ChessField* field) {
    delete field->piece;
  }

  bool ChessBoard::kingInCheck(ChessField* source, ChessField* destination) {
    // find king
    // loop through enemies
    // if any of them can move to that place then king is in check

    // make the move at the beginning, role back at the end
    int number_of_enemies = 0;
    ChessField* king_field;
    ChessField* field;
    ChessField* enemy_fields[16]; // make this constant
    for (int row=0; row < 8 /* const*/; row++) {
      for (int col=0; col < 8 /* const*/; col++) {
    field = board[row][col];
    if (!field->piece) continue;
    if (field->piece->is_white == white_turn) {
      if(dynamic_cast<King*>(field->piece)) {
        king_field = field;
      }
    } else {
      enemy_fields[number_of_enemies] = field;
      number_of_enemies++;
    }
      }
    }

    for (int enemy = 0; enemy<number_of_enemies; enemy++) {
      if(enemy_fields[enemy]->piece
     ->canMakeMove(enemy_fields[enemy], king_field, board)) return true;
    }

      
    return false;
  };

bool  ChessBoard::checkStaleMate() {
    int number_of_fields = 0;
    ChessField* friendly_fields[16]; // replace with constant
    ChessField* field;
    
    for (int row=0; row < 8 /* const*/; row++) {
      for (int col=0; col < 8 /* const*/; col++) {
    field = board[row][col];
    if (!field->piece) continue;
    if (field->piece->is_white == white_turn) {
      friendly_fields[number_of_fields] = field;
      number_of_fields++;
    }
      }

    }

    
    for(int current_field=0; current_field < number_of_fields; current_field++) {
      for (int row=0; row < 8 /* const*/; row++) {
    for (int col=0; col < 8 /* const*/; col++) {
      field = board[row][col];
      if (canMakeMove(friendly_fields[current_field], field)) return false;
    }
      }

    }
    return true;
      
  }

ChessBoard::ChessBoard() { setUpBoard(); }
  ChessBoard::~ChessBoard() { clearBoard(); }
  
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
  void ChessBoard::submitMove(const char* source, const char* destination)  {
    int source_row, source_col, destination_row, destination_col;
    if (!charPositionToIntPosition(source, source_row, source_col)) return;
    if (!charPositionToIntPosition(destination, destination_row, destination_col)) return;
    
    ChessField* source_field = board[source_row][source_col];
    ChessField* destination_field = board[destination_row][destination_col];
    Piece* piece_to_move = source_field->piece;

    if(!canMakeMove(source_field, destination_field)) return;

    Piece* dead_piece = nullptr;
    if(source_field->piece && destination_field->piece) {
      if (source_field->piece->is_white != source_field->piece->is_white) {
    dead_piece = destination_field->piece;
      }
    }
    destination_field->piece = source_field->piece;
    source_field->piece = nullptr;

    if (dead_piece) {
      delete dead_piece;
    }
    destination_field->piece->hasMoved();
    white_turn = !white_turn;

    display_board(); // delete
    
    checkStaleMate();
    
  }

  bool ChessBoard::canMakeMove(ChessField* source_field, ChessField* destination_field) {
    
    // check if the  move actually moves a piece
    if (source_field == destination_field) {
      //fprintf(stderr, "You must move a piece, it cannot stay on same field");
      return false;
    }

    // check whether there is a piece on the board in the source position
    if (!source_field->piece) {
      //fprintf(stderr, "There is no chess piece on the field you have selected "
          "(%s). Thus the move is invalid", source_field->char_position);
      return false;
    }

    // check whether source piece belongs to player
    if((int)white_turn != source_field->piece->is_white) {
      //fprintf(stderr, "%s is allowed to move. The piece in position %s is %s"
          " .Thus the move is invalid.",
          (white_turn ? "White" : "Black"),
          source_field->char_position,
          (source_field->piece->is_white ? "White" : "Black"));
      return false;
    }

    // check if move is allowed by the rules of the piece
    if(!source_field->piece->canMakeMove(source_field, destination_field, board)) {
      return false;
    }

   
    // check if friendly figurine on the destination field
    if(source_field->piece && destination_field->piece) {
      if (source_field->piece->is_white == source_field->piece->is_white) {
    //fprintf(stderr, "There is a piece of the same colour on destination field %s "
        ".Thus the move is invalid.", destination_field->char_position);
    return false;
      }
    }

    Piece* dead_piece = nullptr;
    if(source_field->piece && destination_field->piece) {
      if (source_field->piece->is_white != source_field->piece->is_white) {
    dead_piece = destination_field->piece;
      }
    }
    destination_field->piece = source_field->piece;
    source_field->piece = nullptr;

    
    // check if king in check after move
    bool return_value = true;
    if(kingInCheck(source_field, destination_field)) {
      //fprintf(stderr, "This move cannot be done since your king will be in check after the move");
      return_value = false;
    };

    source_field->piece = destination_field->piece;
    destination_field->piece = dead_piece; 
     

    return return_value;
  }





