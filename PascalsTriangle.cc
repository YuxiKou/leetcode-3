/*
  Given numRows, generate the first numRows of Pascal's triangle.

  For example, given numRows = 5,
  Return

  [
  [1],
  [1,1],
  [1,2,1],
  [1,3,3,1],
  [1,4,6,4,1]
  ]
*/
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int> > generate(int numRows) {
    std::vector<std::vector<int> > result;
    for(int i = 0; i < numRows; ++ i)
    {
      std::vector<int> oneRow(i + 1, 0);
      for(int j = 0; j < i + 1; ++ j)
      {
        oneRow[j] = (j == 0 || j == i ) ? 1 : result[i-1][j-1] + result[i-1][j];
      }
      result.push_back(oneRow);
    }
    return result;
  }
};
