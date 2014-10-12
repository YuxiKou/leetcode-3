/*
  Given an array of integers, every element appears three times except for one. Find that single one.

  Note:
  Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
/*
f(0, 0, 0) -> 1, 0, 0
f(1, 0, 0) -> 0, 1, 0
f(0, 1, 0) -> 0, 0, 1
f(0, 0, 1) -> 0, 0, 0
 */

#include <vector>

class Solution {
 public:
  int singleNumber(int A[], int n) {
    int ones = 0;
    int twos = 0;
    int threes = 0;

    for(int i = 0; i < n; ++ i)
    {
      twos |= ones & A[i];
      ones ^= A[i];
      threes = ones & twos;
      ones &= ~threes;
      twos &= ~threes;
    }

    return ones;
  }
};
