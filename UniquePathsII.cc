/*
  Follow up for "Unique Paths":

  Now consider if some obstacles are added to the grids. How many unique paths would there be?

  An obstacle and empty space is marked as 1 and 0 respectively in the grid.

  For example,
  There is one obstacle in the middle of a 3x3 grid as illustrated below.

  [
  [0,0,0],
  [0,1,0],
  [0,0,0]
  ]
  The total number of unique paths is 2.

  Note: m and n will be at most 100.
*/

#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int m = obstacleGrid.size();
    if(m == 0) return 0;
    int n = obstacleGrid[0].size();
    if(n == 0) return 0;

    vector<int> temp(n, 0);
    vector<vector<int> > result(m, temp);

    if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
    result[0][0] = 1;
    for(int i = 1; i < m; ++ i)
    {
      result[i][0] = obstacleGrid[i][0] == 1 ? 0 : result[i-1][0];
    }

    for(int j = 1; j < n; ++ j)
    {
      result[0][j] = obstacleGrid[0][j] == 1 ? 0 : result[0][j-1];
    }
    for(int i = 1; i < m; ++i)
    {
      for(int j = 1; j < n; ++j)
      {
        result[i][j] = obstacleGrid[i][j] == 1 ? 0 : result[i-1][j] + result[i][j-1];
      }
    }
    return result[m-1][n-1];
  }
};
