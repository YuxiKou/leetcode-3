/*
  Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

  You may assume no duplicates in the array.

  Here are few examples.
  [1,3,5,6], 5 → 2
  [1,3,5,6], 2 → 1
  [1,3,5,6], 7 → 4
  [1,3,5,6], 0 → 0
*/
class Solution {
 public:
  int searchInsert(int A[], int n, int target)
  {
    if(n < 1) return 0;
    int lower = 0;
    int upper = n - 1;
    if(target <= A[0]) return 0;
    if(target > A[n-1]) return n;
    while(lower < upper)
    {
      int mid = lower + (upper - lower) / 2;
      if(target == A[mid]) return mid;
      else if(target < A[mid]) upper = mid;
      else lower = mid + 1;
    }
    return upper;
  }
};
