/*
  Given a set of distinct integers, S, return all possible subsets.

  Note:
  Elements in a subset must be in non-descending order.
  The solution set must not contain duplicate subsets.
  For example,
  If S = [1,2,3], a solution is:

  [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
  ]
*/

/*
  for each integer from 0 to pow(n), it corresponds to a subset.
  note:
  cmath
  pow
  >>=
  sort
*/
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  vector<vector<int> > subsets(vector<int> &S) {
    int n = S.size();
    int size = pow(2, n);
    sort(S.begin(), S.end());

    vector<vector<int> > result;
    for(int i = 0; i < size; ++ i) {
      int num = i;
      vector<int> curResult;
      for(int j = 0; j < n; ++ j) {
        if(num % 2 == 1) curResult.push_back(S[j]);
        num >>= 1;
      }
      result.push_back(curResult);
    }
    return result;
  }
};
