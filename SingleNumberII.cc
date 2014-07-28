/*
  Given an array of integers, every element appears three times except for one. Find that single one.

  Note:
  Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include <vector>

class Solution {
 public:
  int singleNumber(int A[], int n) {
    const int INT_SIZE = 32;
    std::vector<int> sum(INT_SIZE, 0);
    for(int i = 0; i < n; ++ i)
    {
      int curNum = A[i];
      int bit = INT_SIZE;
      while(curNum > 0)
      {
        sum[--bit] += curNum % 2;
        curNum /= 2;
      }
    }

    int result = 0;
    for(int i = 0; i < INT_SIZE; ++ i)
    {
      result += (sum[i] % 3) << (31 - i);
    }
    return result;
  }
};
