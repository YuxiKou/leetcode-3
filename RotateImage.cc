/*
  You are given an n x n 2D matrix representing an image.

  Rotate the image by 90 degrees (clockwise).

  Follow up:
  Could you do this in-place?
*/

/*
  1 2 3    7 4 1
  4 5 6 -> 8 5 2
  7 8 9    9 6 3

  flip left-right
  flip topleft-bottomright
*/
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int> > &matrix) {
    rotateLR(matrix);
    rotateTB(matrix);
  }
  void rotateLR(vector<vector<int> > &matrix) {
    for(int i = 0; i < matrix.size(); ++i) {
      std::reverse(matrix[i].begin(), matrix[i].end());
    }
  }
  void rotateTB(vector<vector<int> > &matrix) {
    int n = matrix.size();

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n - i; ++j) {
        std::swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
      }
    }
  }
};
