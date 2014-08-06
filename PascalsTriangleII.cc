/*
  Given an index k, return the kth row of the Pascal's triangle.

  For example, given k = 3,
  Return [1,3,3,1].

  Note:
  Could you optimize your algorithm to use only O(k) extra space?
*/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> result(rowIndex + 1, 1);
    long long cur = 1;
    for(int i = 1; i < rowIndex; ++ i)
    {
      cur = cur * (rowIndex - i + 1) / i;
      result[i] = cur;
    }
    return result;
  }
};
