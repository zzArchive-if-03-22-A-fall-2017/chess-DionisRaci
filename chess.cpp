/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			      chess.c
 * Author:			    Dionis Raci
 * Due Date:		    October 13, 2017
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */

 #include <stdlib.h>
 #include "general.h"
 #include "chess.h"

bool is_piece(struct ChessPiece cp, enum PieceColor color, enum PieceType type)
{
  if (cp.color == color && cp.type == type)
  {
    return true;
  }
  else return false;
}

void init_chess_board(ChessBoard chess_board){
for (int i = 0; i < 8; i++)
{
  for (int j = 0; j < 8; j++)
  {
    chess_board[i][j].is_occupied = false;
  	ChessPiece p = {White ,NoPiece};
  	chess_board[i][j].piece = p;
  }
 }
}

struct ChessSquare * get_square (ChessBoard chess_board, File file, Rank rank){
  if (file < 'a' || file > 'h' ||rank <1 || rank >8 )
  {
    return 0;
  }
  else
  {
    return &chess_board[rank -1][file - 'a'];
  }
}

bool is_square_occupied(ChessBoard chess_board, File file, Rank rank){
  if (chess_board[rank-1][file -'a'].is_occupied == false)
  {
    return false;
  }
  else{
    return true;
  }
}

bool add_piece (ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece)
{
  if (!is_square_occupied(chess_board, file, rank) && file >= 'a' && file <= 'h' && rank<9 && rank >0)
  {
    chess_board[rank-1][file-'a'].piece = piece;
    chess_board[rank-1][file-'a'].is_occupied = true;
    return true;
  }
  return false;
}
struct ChessPiece 	get_piece (ChessBoard chess_board, File file, Rank rank){
struct ChessPiece cp;
  if (!is_square_occupied(chess_board, file, rank) ||(file < 'a' || file > 'h' ||rank <1 || rank >8))
  {
    cp.type = NoPiece;
    return cp;
  }
  else{
    return chess_board[rank-1][file-'a'].piece;
  }
}
void 	setup_chess_board (ChessBoard chess_board)
{
  init_chess_board(chess_board);
  struct ChessPiece white_rook = {White, Rook};
  struct ChessPiece white_knight = {White, Knight};
  struct ChessPiece white_bishop = {White, Bishop};
  struct ChessPiece white_queen = {White, Queen};
  struct ChessPiece white_king = {White, King};
  struct ChessPiece white_pawn ={White, Pawn};

  add_piece(chess_board, 'a', 1, white_rook);
  add_piece(chess_board, 'b', 1, white_knight);
  add_piece(chess_board, 'c', 1, white_bishop);
  add_piece(chess_board, 'd', 1, white_queen);
  add_piece(chess_board, 'e', 1, white_king);
  add_piece(chess_board, 'f', 1, white_bishop);
  add_piece(chess_board, 'g', 1, white_knight);
  add_piece(chess_board, 'h', 1, white_rook);
  for (char i = 'a'; i <= 'h'; i++) {
  add_piece(chess_board, i, 2, white_pawn);
}

struct ChessPiece black_rook = {Black, Rook};
struct ChessPiece black_knight = {Black, Knight};
struct ChessPiece black_bishop = {Black, Bishop};
struct ChessPiece black_queen = {Black, Queen};
struct ChessPiece black_king = {Black, King};
struct ChessPiece black_pawn ={Black, Pawn};

add_piece(chess_board, 'a', 8, black_rook);
add_piece(chess_board, 'b', 8, black_knight);
add_piece(chess_board, 'c', 8, black_bishop);
add_piece(chess_board, 'd', 8, black_queen);
add_piece(chess_board, 'e', 8, black_king);
add_piece(chess_board, 'f', 8, black_bishop);
add_piece(chess_board, 'g', 8, black_knight);
add_piece(chess_board, 'h', 8, black_rook);
for (char i = 'a'; i <= 'h'; i++)
{
  add_piece(chess_board, i, 7, black_pawn);
}

for (int i = 3; i < 6; i++) {
  for (int j = 0; j< 8; j++) {
    chess_board[i][j].is_occupied = false;
  }
}
}

bool 	remove_piece (ChessBoard chess_board, File file, Rank rank)
{
  if (!is_square_occupied(chess_board, file, rank) ||(file < 'a' || file > 'h' ||rank <1 || rank >8))
  {
    return false;
  }
  chess_board[rank-1][file-'a'].is_occupied = false;
  return true;
}

bool 	squares_share_file (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
if ((s1_f < 'a' || s1_f > 'h' || s1_r <1 || s1_r >8) || (s2_f < 'a' || s2_f > 'h' || s2_r <1 || s2_r >8) || s1_f != s2_f)
{
  return false;
}
  return true;
}
bool 	squares_share_rank (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
  if ((s1_f < 'a' || s1_f > 'h' || s1_r <1 || s1_r >8) || (s2_f < 'a' || s2_f > 'h' || s2_r <1 || s2_r >8) || s1_r != s2_r)
  {
    return false;
  }
    return true;
}
bool 	squares_share_diagonal (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
 if (s1_f < 'a' || s1_f > 'h' || s1_r <1 || s1_r >8 || s2_f < 'a' || s2_f > 'h' || s2_r <1 || s2_r >8)
 {
   return false;
 }
 else if(s1_f - s2_f == s1_r - s2_r )
 {
   return true;
 }
 else if (s1_f > s2_f ) {
   if (s1_f- s2_f == s2_r - s1_r)
   {
     return true;
   }
 }
 else if (s1_r > s2_r) {
   if (s2_r- s1_r == s1_f - s2_f)
   {
     return true;
   }
 }
  return false;
}

bool 	squares_share_knights_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
if ((s1_f - s2_f == 1|| s2_f - s1_f == 1) && (s1_r- s2_r == 2 || s2_r- s1_r == 2))
{
  return true;
}
else if ((s1_f - s2_f == 2 || s2_f - s1_f == 2) && (s1_r - s2_r == 1 || s2_r - s1_r == 1))
{
  return true;
}
else return false;
}

bool 	squares_share_pawns_move (enum PieceColor color, enum MoveType move, File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
if (color == White) {
  if (move == NormalMove && s1_f == s2_f && s1_r < s2_r)
   {
      if ((s1_r >2) && (s2_r - s1_r != 1) || (s1_r <2))
      {
        return false;
      }
      return true;
  }
  else if (move == CaptureMove  && s2_r - s1_r == 1)
  {
    return true;
  }
  else return false;
}
else if (color == Black)
{
  if (move == NormalMove && s1_f == s2_f && s1_r > s2_r && s2_r <7)
  {
    if (s1_r != 7 && (s1_r - s2_r != 1))
    {
      return false;
    }
      return true;
  }
  else if (move == CaptureMove && s1_r - s2_r == 1)
   {
    return true;
  }
  else return false;
}
  return false;
}

bool 	squares_share_queens_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  if ((s1_f < 'a' || s1_f > 'h' || s1_r <1 || s1_r >8) || (s2_f < 'a' || s2_f > 'h' || s2_r <1 || s2_r >8))
  {
    return false;
  }
  if ((s1_f - s2_f == 1 ||s2_f-s1_f == 1) == (s1_r - s2_r == 1 || s2_r - s1_r == 1) )
  {
    return true;
  }
  else if (s1_f == s2_f || s1_r == s2_r)
  {
    return true;
  }
  else if (s1_f == s2_f || s1_r == s2_r)
  {
    return true;
  }
}
bool 	squares_share_kings_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  if ((s1_f < 'a' || s1_f > 'h' || s1_r <1 || s1_r >8) || (s2_f < 'a' || s2_f > 'h' || s2_r <1 || s2_r >8))
  {
    return false;
  }
  else if (s1_f == s2_f && (s1_r - s2_r == 1 || s2_r - s1_r == 1) )
  {
    return true;
  }
  else if (s1_r == s2_r && (s1_f - s2_f == 1 || s2_f - s1_f == 1))
  {
    return true;
  }
  else if ((s1_f - s2_f == 1 || s2_f - s1_f == 1) && (s1_r - s2_r == 1 || s2_r - s1_r == 1))
  {
    return true;
  }
  return false;
}
