// The DLL(list<int>) stores nothing but the values of the 'key'
// To find the corresponding values and the DLL location, we use the map

// In queue or DLL
// ('FRONT',push_front())<---------->('REAR',pop())

// Problem Link: https://leetcode.com/problems/lru-cache/
class LRUCache{
  list<int> recent; // doubly linked list with map
  //{key,{value,key iterator of the dll}}
  unordered_map<int,pair<int,list<int>:: iterator>> cache;
  int capacity;
  public:
    LRUCache{int capacity}{
      this -> capacity = capacity;
    }

    void moveForward(int key){
      recent.erase(cache[key].second); // NOTE: Careful HERE.
      recent.push_front(key);
      cache[key].second = recent.begin();
    }

    int get(int key){
      if(cache.find(key) != cache.end()){
        moveForward(key);
        return cache[key].first;
      }
      return -1;
    }

    void put(int key, int value){
      if(cache.find(key) != cache.end()){
        moveForward(key);
        cache[key].first = value;
      }else if(cache.size()==this->capacity){
        int toDelete = recent.back();
        recent.pop_back();
        recent.push_front(key);
        cache.erase(toDelete);
        cache.insert({key,make_pair(value,recent.begin())});
      }else if(cache.size()<this->capacity){
        recent.push_front(key);
        cache.insert({key,make_pair(value,recent.begin())});
      }
    }

};
