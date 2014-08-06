/*
  Given a sorted array of integers, find the starting and ending position of a given target value.

  Your algorithm's runtime complexity must be in the order of O(log n).

  If the target is not found in the array, return [-1, -1].

  For example,
  Given [5, 7, 7, 8, 8, 10] and target value 8,
  return [3, 4].
*/
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(int A[], int n, int target) {
    int begin = search(A, n, (double)target - 0.5);
    int end = search(A, n, (double)target + 0.5);
    vector<int> result(2, -1);
    if(begin != end)
    {
      result[0] = begin;
      result[1] = end - 1;
    }
    else if(A[begin] == target)
    {
      result[0] = begin;
      result[1] = end;
    }
    return result;
  }

  int search(int A[], int n, double target)
  {
    if(A[0] > target) return 0;
    if(A[n-1] < target) return n;
    int lower = 0;
    int upper = n - 1;
    while(lower < upper)
    {
      int mid = lower + (upper - lower) / 2;
      if(A[mid] < target)
      {
        lower = mid + 1;
      }
      else
      {
        upper = mid;
      }
    }
    return lower;
  }
};
