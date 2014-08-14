/*
  Given an array of integers, find two numbers such that they add up to a specific target number.

  The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

  You may assume that each input would have exactly one solution.

  Input: numbers={2, 7, 11, 15}, target=9
  Output: index1=1, index2=2
*/
#include <vector>
#include <map>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    map<int, int> hash;
    vector<int> result(2, 0);
    for(vector<int>::size_type i = 0; i < numbers.size(); ++ i)
    {
      if(hash[target-numbers[i]] >= 0)
      {
        result[0] = hash[target-numbers[i]];
        result[1] = i + 1;
      }
      hash[numbers[i]] = i + 1;
    }
    return result;
  }
};
