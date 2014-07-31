/*
  Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

  Note: You can only move either down or right at any point in time.
*/
#include <vector>

using namespace std;
class Solution {
 public:
  int minPathSum(vector<vector<int> > &grid) {
    int m = grid.size();
    if(m == 0) return 0;
    int n = grid[0].size();
    if(n == 0) return 0;

    vector<int> oneRow(n, 0);
    vector<vector<int> > result(m, oneRow);

    result[0][0] = grid[0][0];
    for(int i = 1; i < n; ++ i)
    {
      result[0][i] = result[0][i-1] + grid[0][i];
    }
    for(int i = 1; i < m; ++ i)
    {
      result[i][0] = result[i-1][0] + grid[i][0];
    }

    for(int i = 1; i < m; ++ i)
    {
      for(int j = 1; j < n; ++ j)
      {
        result[i][j] = grid[i][j] + min(result[i-1][j], result[i][j-1]);
      }
    }

    return result[m-1][n-1];
  }
};
