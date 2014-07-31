/*
  Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

  Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

  You are not suppose to use the library's sort function for this problem.
  A rather straight forward solution is a two-pass algorithm using counting sort.
  First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

  Could you come up with an one-pass algorithm using only constant space?
*/
#include <iostream>

class Solution {
 public:
  void sortColors(int A[], int n) {
    int ptrZero = 0;
    int ptrTwo = n - 1;
    int i = 0;
    while(i <= ptrTwo)
    {
      switch(A[i])
      {
        case 0:
          std::swap(A[ptrZero], A[i]);
          while(A[ptrZero] == 0) ++ptrZero;
          if(i < ptrZero) i = ptrZero;
          break;
        case 2:
          std::swap(A[ptrTwo], A[i]);
          while(A[ptrTwo] == 2) --ptrTwo;
          break;
        default:
          ++i;
          break;
      }
    }
  }
};
