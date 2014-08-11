/*
  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

  For example,
  Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

/*
  For each column, find the left and right sides of the highest pillar, the pillar can accommodate area is min (leftMostHeight, rightMostHeight) - height. So,
  1 from left to right scan again, for each column, to obtain the maximum on the left,
  2 from right to left scan again, for each column, the biggest rvalue,
  3 then scanned, each column area and accumulation.
  Also can,
  The 1 scan again, find the highest pillar, the pillar of the array is divided into two halves,
  2 left half,
  3 processing the right half.
*/

class Solution {
 public:
  int trap(int A[], int n) {
    if(n < 3) return 0;
    int leftMax = 0;
    int rightMax = 0;
    int left = 0;
    int right = n - 1;
    int vol = 0;
    while(left < right)
    {
      if(A[left] > leftMax) leftMax = A[left];
      if(A[right] > rightMax) rightMax = A[right];

      if(leftMax < rightMax)
      {
        vol += leftMax - A[left];
        ++left;
      }
      else
      {
        vol += rightMax - A[right];
        --right;
      }
    }
    return vol;
  }
};
