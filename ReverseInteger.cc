/*
  Reverse digits of an integer.

  Example1: x = 123, return 321
  Example2: x = -123, return -321
*/

#include <limits>

class Solution {
 public:
  int reverse(int x) {
    int sign = x > 0 ? 1 : -1;
    x = x > 0 ? x : -x;
    const int IntMax = std::numeric_limits<int>::max();
    const int IntMin = std::numeric_limits<int>::min();
    long result = 0;
    while (x > 0)
    {
      result = result * 10 + x % 10;
      x /= 10;
    }
    result *= sign;
    if(result > IntMax) return IntMax;
    if(result < IntMin) return IntMin;
    return result;
  }
};
