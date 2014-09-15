/*
  Given an input string, reverse the string word by word.

  For example,
  Given s = "the sky is blue",
  return "blue is sky the".
*/
/*
  1. reverse every word
  2. reverse the entire string
*/

#include <string>

using namespace std;

class Solution {
 public:
  void reverseWords(string &s) {
    int n = s.length();
    int start = 0;
    string result = "";

    s = reverse(s);
    while(start < n && s[start] == ' ') ++start;
    while(start < n) {
      while(start < n && s[start] == ' ') ++start;
      int end = start + 1;
      while(end < n && s[end] != ' ') ++end;
      if(end > n) break;
      string word = reverse(s.substr(start, end - start));
      if(result.length() != 0) result += ' ';
      result += word;
      start = end;
    }
    s = result;
  }

  string reverse(string s)
  {
    std::reverse(s.begin(), s.end());
    return s;
  }
};
