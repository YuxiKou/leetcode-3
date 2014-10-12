/*
  Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

  For example,
  Given [100, 4, 200, 1, 3, 2],
  The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

  Your algorithm should run in O(n) complexity.
*/
#include <vector>
#include <map>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int> &num) {
    map<int, int> map;
    int max = 1;
    for(int i = 0; i < num.size(); ++i)
    {
      //eliminates duplicates
      if(map[num[i]] > 0) continue;
      map[num[i]] = 1;
      if(map[num[i] - 1] > 0)
        max = std::max(max, merge(map, num[i] - 1, num[i]));
      if(map[num[i] + 1] > 0)
        max = std::max(max, merge(map, num[i], num[i] + 1));
    }
    return max;
  }
  int merge(map<int, int> &map, int left, int right)
  {
    int low = left - map[left] + 1;
    int high = right + map[right] - 1;
    int len = high - low + 1; //equals to map[left] + map[right]
    map[low] = len;
    map[high] = len;
    return len;
  }
};
