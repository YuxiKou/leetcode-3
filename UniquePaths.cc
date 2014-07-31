/*
  A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

  The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

  How many possible unique paths are there?
  Note: m and n will be at most 100.
*/
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
      std::vector<int> oneRow(n, 0);
      std::vector<std::vector<int> > result(m, oneRow);
      for(int i = 0; i < m; ++ i)
      {
        for(int j = 0; j < n; ++ j)
        {
          result[i][j] = (i == 0 || j == 0) ? 1 : result[i-1][j] + result[i][j-1];
        }
      }
      return result[m-1][n-1];
    }
};
