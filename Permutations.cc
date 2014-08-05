/*
  Given a collection of numbers, return all possible permutations.

  For example,
  [1,2,3] have the following permutations:
  [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include <vector>

class Solution {
 public:
  std::vector<std::vector<int> > permute(std::vector<int> &num) {
    std::vector<std::vector<int> > result;
    permutePrivate(num, 0, result);
    return result;
  }
  void permutePrivate(std::vector<int> &num, int curIndex, std::vector<std::vector<int> > &result)
  {
    int size = num.size();
    if(size == curIndex)
    {
      result.push_back(num);
      return;
    }
    for(int i = curIndex; i < size; ++ i)
    {
      std::swap(num[curIndex], num[i]);
      permutePrivate(num, curIndex + 1, result);
      std::swap(num[curIndex], num[i]);
    }
  }
};
