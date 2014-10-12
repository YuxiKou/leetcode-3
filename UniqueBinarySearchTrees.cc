/*
  Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

  For example,
  Given n = 3, there are a total of 5 unique BST's.

  1         3     3      2      1
  \       /     /      / \      \
  3     2     1      1   3      2
  /     /       \                 \
  2     1         2                 3
*/

/*
  algorithm
  Solution:
  f(0) = 1
  f(1) = 1
  f(2) = f(0) * f(1) + f(1) * f(0)
  f(3) = f(0) * f(2) + f(1) * f(1) + f(2) * f(0)
  f(n) = f(0) * f(n-1) + f(1) * f(n-2) + ... + f(n-1) * f(0)
       = 2 * [f(0) * f(n-1) + f(1) * f(n-2) + ... + f(n/2) * f(n/2)] if n mod 2 = 0
       = 2 * [f(0) * f(n-1) + f(1) * f(n-2) + ... + f((n-1)/2) * f((n+1)/2)] if n mod 2 = 1
*/

#include <vector>

class Solution {
 public:
  int numTrees(int n)
  {
    if(n < 2) return 1;
    std::vector<long> num(n + 1, 0);
    num[0] = num[1] = 1;
    for(int i = 2; i <= n; ++ i)
    {
      for(int j = 0; j < i; ++ j)
      {
        num[i] += num[j] * num[i-j-1];
      }
    }
    return num[n];
  }
};
