/*
  Follow up for "Remove Duplicates":
  What if duplicates are allowed at most twice?

  For example,
  Given sorted array A = [1,1,1,2,2,3],

  Your function should return length = 5, and A is now [1,1,2,2,3].
*/

class Solution {
 public:
  int removeDuplicates(int A[], int n) {
    if(n < 3) return n;
    int length = 0;
    int curIndex = 0;
    int i;

    /*
      1      1      2     2      2      2      2      3
                                                              n
                                                      cur
                                        i
                                 length
     */
    while(curIndex < n)
    {
      i = curIndex ++;
      while(curIndex < n && A[i] == A[curIndex]) ++ curIndex;
      A[length++] = A[i++];
      if(i < curIndex) A[length++] = A[i++];
    }
    return length;
  }
};
