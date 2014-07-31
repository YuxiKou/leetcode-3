/*
  Given a non-negative number represented as an array of digits, plus one to the number.

  The digits are stored such that the most significant digit is at the head of the list.
*/
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    int size = digits.size();
    if(size == 0) return digits;

    ++digits[size-1];
    for(int i = size - 1; i > 0; -- i)
    {
      if(digits[i] < 10)
        break;
      ++digits[i-1];
      digits[i] -= 10;
    }

    if(digits[0] > 9)
    {
      vector<int> result(size + 1, 0);
      result[0] = 1;
      return result;
    }
    return digits;
  }
};
