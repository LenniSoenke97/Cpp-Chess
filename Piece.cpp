#include"Piece.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;


bool Piece::canMoveDiagonal(ChessField* source,
			    ChessField* destination,
			    ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]) const
{
  int difference_row = abs(source->row - destination->row);
  int difference_col = abs(source->col - destination->col);
  if (difference_row != difference_col) return false;

  int row_change = (source->row > destination->row) ? -1 : 1;
  int col_change = (source->col > destination->col) ? -1 : 1;
  int current_row = source->row+row_change, current_col = source->col+col_change;
  ChessField* current_field;
  while(current_row != destination->row && current_col != destination->col) {
    current_field = board[current_row][current_col];
    if(current_field->piece) return false;
    current_row += row_change;
    current_col += col_change;
  }
    
  return true;
}

bool Piece::canMoveHorizontal(ChessField* source,
			      ChessField* destination,
			      ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]) const
{
  if (source->row != destination->row) return false;
    
  int col_change = (source->col > destination->col) ? -1 : 1;
  int current_col = source->col+col_change;
  ChessField* current_field;
  while(current_col != destination->col) {
    current_field = board[current_col][source->row];
    if(current_field->piece) return false;
    current_col += col_change;
  }

  return true;
}

bool Piece::canMoveVertical(ChessField* source,
			    ChessField* destination,
			    ChessField* board[NUM_OF_ROWS][NUM_OF_COLS]) const
{
  if (source->col != destination->col) return false;

  ChessField* current_field;
  int row_change = (source->row > destination->row) ? -1 : 1;
  int current_row = source->row+row_change;
  while(current_row != destination->row) {
    current_field = board[current_row][source->col];
    if(current_field->piece) return false;
    current_row += row_change;
  }

  return true;
    
};

bool Piece::isWithinMaxDistance(ChessField* source,
				ChessField* destination,
				int max_distance) const
{
  int row_distance = abs(source->row - destination->row);
  int col_distance = abs(source->col - destination->col); 
  int source_to_dest_distance = (row_distance < col_distance) ? col_distance : row_distance;
  return source_to_dest_distance <= max_distance;
}

void Piece::hasMoved()
{
  has_moved = true;
}

bool Piece::getHasMoved() const
{
  return this->has_moved;
}
