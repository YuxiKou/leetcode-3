/*
  Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

  For example,
  If n = 4 and k = 2, a solution is:

  [
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
  ]
*/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;
    vector<int> temp;
    combinePrivate(1, n, k, temp, result);
    return result;
  }

  void combinePrivate(int begin, int end, int k, vector<int> &cur, vector<vector<int> > &result)
  {
    //this needs to be done before checking begin > end
    if(k == 0)
    {
      if(cur.size() > 0)
      {
        result.push_back(cur);
      }
      return;
    }
    if(begin > end)
    {
      return;
    }

    //boundary check for i!!!! i <= end - k + 1
    for(int i = begin; i <= end - k + 1; ++i)
    {
      cur.push_back(i);
      combinePrivate(i + 1, end, k - 1, cur, result);
      cur.pop_back();
    }
  }
};
