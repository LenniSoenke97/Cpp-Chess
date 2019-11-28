#include"Piece.hpp"
#include"../ChessField.hpp"

  bool Piece::isDiagonal(ChessField* source,
		  ChessField* destination,
		  ChessField* board[8][8]) {
    int difference_row = abs(source->row - destination->row);
    int difference_col = abs(source->col - destination->col);
    if (difference_row != difference_col) return false;


    int row_change = (source->row > destination->row) ? -1 : 1;
    int col_change = (source->col > destination->col) ? -1 : 1;
    int current_row = source->row+row_change, current_col = source->col+col_change;
    Piece* current_field;

    // check no piece is blocking
    while(current_row != destination->row && current_col != destination->col) {
      current_field = board[current_row][current_col];
      if(current_field->piece) {
	fprintf(stderr, "This move is invalid because there is a piece at position " "%s that blocks the piece from %s from moving to %s",
		current_field->char_position;
		source->char_postion;
		destination->char_postion);  
	return false;
      };

      current_row += row_change;
      current_col += col_change;
    }
    
    return true;
  };

bool Piece::isHorizontal(ChessField* source,
		    ChessField* destination,
		    ChessField* board[8][8]) {
    if (source->col != destination->col) return false;
    
    ChessField* current_field;
    int row_change = (source->row > destination->row) ? -1 : 1;
    int current_row = source->row+row_change;
    while(current_row != destination->row) {
      current_field = board[current_row][source->col];
      if(current_field->piece) {
	fprintf(stderr, "This move is invalid because there is a piece at position "
    "%s that blocks the piece from %s from moving to %s",
		current_field->char_position;
		source->char_postion;
		destination->char_postion);  
	return false;
      };

      current_row += row_change
    }

    return true;
    
  };

bool Piece::isVertical(ChessField* source,
		  ChessField* destination,
		  ChessField* board[8][8]) {
    if (source->row != destination->row) return false;
    
    int col_change = (source->col > destination->col) ? -1 : 1;
    int current_col = source->col+col_change;
    while(current_col != destination->col) {
      current_field = board[current_col][source->row];
      if(current_field->piece) {
	fprintf(stderr, "This move is invalid because there is a piece at position "
    "%s that blocks the piece from %s from moving to %s",
		current_field->char_position;
		source->char_postion;
		destination->char_postion);  
	return false;
      };

      current_col += col_change
    }

    return true;
  }

bool Piece::isWithinMaxDistance(ChessField* source,
		  ChessField* destination){
    int source_to_dest_distance = max(abs(source->row - destination->row),
				      abs(source->col - destination->col));
    return max_distance < source_to_dest_distance;
  }

virtual void Piece::hasMoved() {
  has_moved = true;
}

