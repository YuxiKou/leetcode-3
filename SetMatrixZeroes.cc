/*
  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

#include <vector>

using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int> > &matrix) {
    int m = matrix.size();
    if(m == 0) return;
    int n = matrix[0].size();
    if(n == 0) return;

    vector<bool> row(m, false);
    vector<bool> col(n, false);

    for(int i = 0; i < m; ++ i)
    {
      for(int j = 0; j < n; ++ j)
      {
        if(matrix[i][j] == 0)
        {
          row[i] = true;
          col[j] = true;
        }
      }
    }
    for(int i = 0; i < m; ++ i)
    {
      if(row[i] == true)
      {
        for(int j = 0; j < n; ++ j)
        {
          matrix[i][j] = 0;
        }
      }
    }

    for(int j = 0; j < n; ++ j)
    {
      if(col[j] == true)
      {
        for(int i = 0; i < m; ++ i)
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
};
