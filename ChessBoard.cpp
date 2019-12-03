#include"ChessBoard.h"
#include"Rook.hpp"
#include"Knight.hpp"
#include"Bishop.hpp"
#include"Queen.hpp"
#include"King.hpp"
#include"Pawn.hpp"

void ChessBoard::clearBoard()
{
  for (int row = 0; row < NUM_OF_ROWS; row++) {
    for (int col = 0; col < NUM_OF_COLS; col++) {
      if(!board[row][col]) continue;
      if(board[row][col]->piece) delete board[row][col]->piece;
      delete board[row][col];
    }
  } 
}

void ChessBoard::setupBoard()
{
  bool isWhite = true;
  board[0][0] = new ChessField(0, 0, new Rook(isWhite));
  board[0][1] = new ChessField(0, 1, new Knight(isWhite));
  board[0][2] = new ChessField(0, 2, new Bishop(isWhite));
  board[0][3] = new ChessField(0, 3, new Queen(isWhite));
  board[0][4] = new ChessField(0, 4, new King(isWhite));
  board[0][5] = new ChessField(0, 5, new Bishop(isWhite));
  board[0][6] = new ChessField(0, 6, new Knight(isWhite));
  board[0][7] = new ChessField(0, 7, new Rook(isWhite));
  for (int col = 0; col < NUM_OF_COLS; col++) {
    board[1][col] = new ChessField(1, col, new Pawn(isWhite));
  }

  for (int row = 2; row < (NUM_OF_ROWS-2); row++) {
    for (int col = 0; col < NUM_OF_COLS; col++) {
      board[row][col] = new ChessField(row, col);
    }
  }

  isWhite = false;
  board[7][0] = new ChessField(7, 0, new Rook(isWhite));
  board[7][1] = new ChessField(7, 1, new Knight(isWhite));
  board[7][2] = new ChessField(7, 2, new Bishop(isWhite));
  board[7][3] = new ChessField(7, 3, new Queen(isWhite));
  board[7][4] = new ChessField(7, 4, new King(isWhite));
  board[7][5] = new ChessField(7, 5, new Bishop(isWhite));
  board[7][6] = new ChessField(7, 6, new Knight(isWhite));
  board[7][7] = new ChessField(7, 7, new Rook(isWhite));
  for (int col = 0; col < NUM_OF_COLS; col++) {
    board[6][col] = new ChessField(6, col, new Pawn(isWhite));
  }
    
  white_turn = true;
  game_over = false;
  printf("A new chess game is started!\n");
}

bool ChessBoard::charPositionToIntPosition(const char* char_pos, int& int_row_pos, int& int_col_pos)
{
  char char_col_pos = char_pos[0];
  char char_row_pos = char_pos[1];
  int_row_pos = (int)char_row_pos - (int)'1';
  int_col_pos = (int)char_col_pos - (int)'A';
  if (int_col_pos < 0 || int_row_pos < 0 || int_col_pos >= NUM_OF_COLS || int_row_pos >= NUM_OF_ROWS) { 
    fprintf(stderr, "The given  position %s is invalid \n", char_pos);
    return false;
  }
  return true;
}

bool ChessBoard::kingInCheck()
{
  int number_of_enemies = 0;
  ChessField* king_field;
  ChessField* field;
  ChessField* enemy_fields[NUM_OF_PIECES_PER_PLAYER]; // make this constant
  for (int row=0; row < NUM_OF_ROWS; row++) {
    for (int col=0; col < NUM_OF_COLS; col++) {
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
}

bool ChessBoard::noMovesPossible()
{
  int number_of_fields = 0;
  ChessField* friendly_fields[NUM_OF_PIECES_PER_PLAYER];
  ChessField* field;
    
  for (int row=0; row < NUM_OF_ROWS; row++) {
    for (int col=0; col < NUM_OF_COLS; col++) {
      field = board[row][col];
      if (!field->piece) continue;
      if (field->piece->is_white == white_turn) {
	friendly_fields[number_of_fields] = field;
	number_of_fields++;
      }
    }
  }
    
  for(int current_field=0; current_field < number_of_fields; current_field++) {
    for (int row=0; row < NUM_OF_ROWS; row++) {
      for (int col=0; col < NUM_OF_COLS; col++) {
	field = board[row][col];
	if (friendly_fields[current_field] == field) continue;
	if (canMakeMove(friendly_fields[current_field], field)) {
	  return false;
	}
      }
    }
  }
  return true;
}

bool ChessBoard::isMovement(ChessField* source_field, ChessField* destination_field) const {
  if (source_field == destination_field) {
    if (!virtual_move) fprintf(stderr, "You must move a piece, it cannot stay on same field\n");
    return false;
  }
  return true;
}

bool ChessBoard::isFieldWithPiece(ChessField* source_field) const {
  if (!source_field->piece) {
    if (!virtual_move) fprintf(stderr, "There is no chess piece on the field you have selected "
	    "(%s). Thus the move is invalid. \n", source_field->char_position);
    return false;
  }
  return true;
}

bool ChessBoard::isPlayer(ChessField* source_field) const {
  if(white_turn != source_field->piece->is_white) {
    if (!virtual_move) fprintf(stderr, "%s is allowed to move. The piece in position %s is %s"
	    ". Thus the move is invalid. \n",
	    (white_turn ? "White" : "Black"),
	    source_field->char_position,
	    (source_field->piece->is_white ? "White" : "Black"));
    return false;
  }
  return true;
}

void ChessBoard::printMovementError(ChessField* source_field, ChessField* destination_field) const {
  if (virtual_move) return;
  if (!source_field->piece) return;
  fprintf(stderr, "Could not move %s's %s from %s to %s \n",
	  (white_turn ? "White" : "Black"),
	  source_field->piece->display(),
	  source_field->char_position,
	  destination_field->char_position);
  return;
}

void ChessBoard::printMovement(ChessField* source_field, ChessField* destination_field, bool kill) const {
  if(virtual_move) return;
  printf("%s's %s moves from %s to %s ",
	 (white_turn ? "White" : "Black"),
	 source_field->piece->display(),
	 source_field->char_position,
	 destination_field->char_position
	 ); 
  if (kill) {
    printf("taking %s's %s \n",
	   (white_turn ? "Black" : "White"),
	   destination_field->piece->display());
  } else {
    printf("\n");
  }
}

void ChessBoard::handleGameResult(bool king_in_check, bool no_moves_possible) {
  if (no_moves_possible) {
    game_over = true;
    if (king_in_check) {
      printf("%s is in checkmate \n",
	     (white_turn ? "White" : "Black"));
    }
    else {
      printf("Game over - stalemate \n");
    }
  }
  else {
    if (king_in_check) {
      printf("%s is in check \n",
	     (white_turn ? "White" : "Black")
	     );
    }
  }
}

bool ChessBoard::destinationFieldIsFriendly(ChessField* source_field, ChessField* destination_field) const {
  if(source_field->piece && destination_field->piece) {
    if (source_field->piece->is_white == destination_field->piece->is_white) {
      return true;
    }
  }
  return false;
}

bool ChessBoard::canMakeMove(ChessField* source_field, ChessField* destination_field)
{
  if(!isFieldWithPiece(source_field)) return false;
  if(!isPlayer(source_field)) return false;
  if(!isMovement(source_field, destination_field)) return false;

  
  if(!source_field->piece->canMakeMove(source_field, destination_field, board)) return false;
  if(destinationFieldIsFriendly(source_field, destination_field)) return false;

  // make below into seperate func
  
  bool can_make_move = true;
  Piece* dead_piece = nullptr;
  if(source_field->piece && destination_field->piece) {
    if (source_field->piece->is_white != destination_field->piece->is_white) {
      dead_piece = destination_field->piece;
    }
  }
  destination_field->piece = source_field->piece;
  source_field->piece = nullptr;

  if(kingInCheck() && !virtual_move) { // find a solution for this
    can_make_move = false;
  }

  source_field->piece = destination_field->piece;
  destination_field->piece = dead_piece;

  return can_make_move;
  
}

ChessBoard::ChessBoard() { setupBoard(); }

ChessBoard::~ChessBoard() { clearBoard(); }

void ChessBoard::resetBoard()
{
  clearBoard();
  setupBoard();
}

void ChessBoard::submitMove(const char* source, const char* destination)
{
  virtual_move = false;
  if (game_over) {
    printf("Game is over, please start a new one if you want to play \n");
    return;
  }
  
  int source_row, source_col, destination_row, destination_col;
  if (!charPositionToIntPosition(source, source_row, source_col)) return;
  if (!charPositionToIntPosition(destination, destination_row, destination_col)) return;
    
  ChessField* source_field = board[source_row][source_col];
  ChessField* destination_field = board[destination_row][destination_col];

  if(!canMakeMove(source_field, destination_field)) {
    printMovementError(source_field, destination_field);
    return;
  }
  
  bool kill = false;
  if(source_field->piece && destination_field->piece) {
    if (source_field->piece->is_white != destination_field->piece->is_white) {
      kill = true;
    }
  }
  
  printMovement(source_field, destination_field, kill);

  
  if (kill) delete destination_field->piece;
  destination_field->piece = source_field->piece;
  source_field->piece = nullptr;
  destination_field->piece->hasMoved();
  white_turn = !white_turn;

  virtual_move = true;
  bool king_in_check = kingInCheck();
  virtual_move = false;
  bool no_moves_possible = noMovesPossible();
  handleGameResult(king_in_check, no_moves_possible);

  // display_board(); // delete

}



