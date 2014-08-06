/*
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include <string>
#include <stack>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> pStack;
    for(int i = 0; i < s.length(); ++i)
    {
      switch(s[i])
      {
        case '(': case '[': case '{':
          pStack.push(s[i]);
          break;
        case ')': case ']': case '}':
          if(pStack.empty() || !match(pStack.top(), s[i]))
            return false;
          else
            pStack.pop();
          break;
        default:
          return false;
      }
    }
    return pStack.empty();
  }
  bool match(char left, char right)
  {
    if(left == '(' && right == ')') return true;
    if(left == '[' && right == ']') return true;
    if(left == '{' && right == '}') return true;
    return false;
  }
};
