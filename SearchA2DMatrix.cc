/*
  Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

  Integers in each row are sorted from left to right.
  The first integer of each row is greater than the last integer of the previous row.
  For example,

  Consider the following matrix:

  [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
  ]
  Given target = 3, return true.
*/
#include <vector>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int m = matrix.size();
    if(m == 0) return false;
    int n = matrix[0].size();
    if(n == 0) return false;

    if(target < matrix[0][0] || target > matrix[m-1][n-1]) return false;

    vector<int> one(m, 0);
    for(int i = 0; i < m; ++ i)
    {
      one[i] = matrix[i][0];
    }
    int row = search(one, target);
    if(matrix[row][0] == target) return true;
    if(row == -1) return false;

    int col = search(matrix[row], target);
    if(matrix[row][col] == target) return true;
    return false;

  }
  int search(vector<int> &oneRow, int target)
  {
    int start = 0;
    int end = oneRow.size();
    if(target < oneRow[start]) return -1;
    if(target > oneRow[end-1]) return end - 1;
    int mid;
    while(start < end)
    {
      if(start == end - 1)
      {
        return start;
      }
      mid = start + (end - start) / 2;
      if(target < oneRow[mid])
      {
        end = mid;
      }
      else if(target > oneRow[mid])
      {
        start = mid;
      }
      else
      {
        return mid;
      }
    }
    return start;
  }
};
