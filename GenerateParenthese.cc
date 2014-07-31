/*
  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

  For example, given n = 3, a solution set is:

  "((()))", "(()())", "(())()", "()(())", "()()()"
*/
#include <vector>
#include <string>

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> results;
    std::string str;
    gen(n, n, str, results);
    return results;
  }
  void gen(int open, int close, std::string curStr, std::vector<std::string> &results)
  {
    if(open == 0)
    {
      while(--close >= 0)
      {
        curStr += ')';
      }
      results.push_back(curStr);
      return;
    }
    gen(open - 1, close, curStr + '(', results);
    if(open < close)
    {
      gen(open, close - 1, curStr + ')', results);
    }
  }
};
