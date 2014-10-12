/*
  Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

  get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
  set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache{
 public:
  struct CacheNode
  {
    int key;
    int value;
    CacheNode(int k, int v) : key(k), value(v) {}
  };

  LRUCache(int capacity) {
    this->capacity = capacity;
  }

  int get(int key) {
    if(map.find(key) == map.end())
      return -1;
    updateRecent(key);
    return map[key]->value;
  }

  void set(int key, int value) {
    if(map.find(key) == map.end())
    {
      if(cache.size() >= capacity)
      {
        map.erase(cache.back().key);
        cache.pop_back();
      }
      CacheNode newNode(key, value);
      cache.push_front(newNode);
      map[key] = cache.begin();
      return;
    }
    map[key]->value = value;
    updateRecent(key);
  }
 private:
  int capacity;
  list<CacheNode> cache;
  unordered_map<int, list<CacheNode>::iterator> map;

  //************ use of erase and update pointer
  void updateRecent(int k)
  {
    CacheNode node = *map[k];
    cache.erase(map[k]);
    cache.push_front(node);
    map[k] = cache.begin();
  }
};
