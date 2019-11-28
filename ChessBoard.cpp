#include"ChessBoard.h"

using namespace std;

void ChessBoard::submitMove(const char* source, const char* destination) {
  /*
    1. identify if there is a piece - if no error
    2. identify the piece is part of the player that is currently allowed to move - if no error
    3. check if the piece could hypothetically move to the destination spot if there was nothing blocking it - if no error
    4. check if there is no piece blocking the way
    5. check if the player is currently in check
    6. check if the player is in check after the move
    7. check for stalemate
    8. check if there is a friendly figure in destination - if yes error
    9. check if there is an opposition figure on destination - if yes kill
   */
}
