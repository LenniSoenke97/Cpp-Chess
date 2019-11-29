cc=g++ -Wall -Wextra -g
pieces=Bishop.o Rook.o King.o Queen.o Knight.o Pawn.o
other=ChessBoard.o Piece.o ChessField.o ChessMain.o



chess: $(pieces) $(other)
	$(cc) $^ -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h
	$(cc) $< -c

ChessBoard.o: ChessBoard.cpp ChessBoard.h Piece.o ChessField.o
	$(cc) $< -c

Piece.o: Piece.cpp Piece.hpp ChessField.hpp $(pieces)
	$(cc) $< -c

ChessField.o: ChessField.cpp ChessField.hpp Piece.hpp
	$(cc) $< -c

%.o: %.cpp %.hpp Piece.hpp
	$(cc) $< -c
