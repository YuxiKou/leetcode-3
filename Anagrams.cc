/*
  Given an array of strings, return all groups of strings that are anagrams.

  Note: All inputs will be in lower-case.
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> anagrams(vector<string> &strs)
  {
    map<string, vector<vector<string>::iterator> > dict;
    for(vector<string>::iterator it = strs.begin(); it != strs.end(); ++ it)
    {
      string s = *it;
      std::sort(s.begin(), s.end());
      dict[s].push_back(it);
    }

    vector<string> ret;
    for(map<string, vector<vector<string>::iterator> >::iterator it = dict.begin(); it != dict.end(); ++it)
    {
      if(it->second.size() > 1)
      {
        bool isNeedErase = false;
        for(vector<vector<string>::iterator>::iterator vit = it->second.begin(); vit != it->second.end(); ++vit)
        {
          if(!isNeedErase)
          {
            isNeedErase = true;
          }
          else
          {
            //strs.erase(*vit);
          }
          ret.push_back(**vit);
        }
      }
    }
    return ret;
  }
};
