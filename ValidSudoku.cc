/*
  Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

  The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/

#include <vector>

using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char> > &board) {
    if(board.size() != 9) return false;
    for(int i = 0; i < 9; ++i)
    {
      if(!validRow(i, board) || !validCol(i, board))
      {
        return false;
      }
    }
    for(int i = 0; i < 9; i += 3)
    {
      for(int j = 0; j < 9; j += 3)
      {
        if(!validBlock(i, j, board))
          return false;
      }
    }
    return true;
  }
  bool validRow(int row, vector<vector<char> > &board)
  {
    if(board[row].size() != 9) return false;
    vector<bool> hasNumber(9, false);
    for(int i = 0; i < 9; ++ i)
    {
      if(board[row][i] == '.') continue;
      if(hasNumber[board[row][i]-'0'] == true) return false;
      hasNumber[board[row][i]-'0'] = true;
    }
    return true;
  }
  bool validCol(int col, vector<vector<char> > &board)
  {
    vector<bool> hasNumber(9, false);
    for(int i = 0; i < 9; ++ i)
    {
      if(board[i][col] == '.') continue;
      if(hasNumber[board[i][col]-'0'] == true) return false;
      hasNumber[board[i][col]-'0'] = true;
    }
    return true;
  }
  bool validBlock(int row, int col, vector<vector<char> > &board)
  {
    vector<bool> hasNumber(9, false);
    for(int i = row; i < row + 3; ++ i)
    {
      for(int j = col; j < col + 3; ++ j)
      {
        if(board[i][j] == '.') continue;
        if(hasNumber[board[i][j]-'0'] == true) return false;
        hasNumber[board[i][j]-'0'] = true;
      }
    }
    return true;
  }
};
