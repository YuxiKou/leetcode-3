/*
  Determine whether an integer is a palindrome. Do this without extra space.
*/

//algorithm. also look at K-M-P algorithm. Need to remember this!!!
class Solution {
 public:
  bool isPalindrome(int x) {
    if(x < 0) return false;
    if(x < 10) return true;
    return isPal(x, x);
  }
  bool isPal(int x, int &y)
  {
    if(x < 0) return false;
    if(x == 0) return true;
    if(isPal(x / 10, y) && (x % 10 == y % 10))
    {
      y /= 10;
      return true;
    }
    return false;
  }
};
