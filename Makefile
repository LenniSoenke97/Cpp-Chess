cc=g++ -Wall -Wextra -g
pieces=Piece/Bishop.o Piece/Rook.o Piece/King.o Piece/Queen.o Piece/Knight.o Piece/Pawn.o
other=ChessBoard.o Pawn.o ChessField.o

Chess: $(pieces) $(other)
	$(cc) $^ -o chess

Piece: Piece.cpp Piece.hpp ChessField.hpp
	$(cc) $< -c

ChessField: ChessField.cpp ChessField.hpp Piece.hpp
	$(cc) $< -c

ChessBoard: ChessBoard.cpp ChessBoard.hpp Piece.hpp ChessField.hpp
	$(cc) $< -c

Piece/%.o: Piece/%.hpp Piece/%.cpp ../ChessBoard.hpp Piece.hpp
	$(cc) $< -c
