class LRU{
  list<int> dll;
  unordered_map<int,pair<int,list<int>:iterator>> cache;
  int capacity;
  LRU(int capacity){
    this->capacity = capacity;

void moveForward(int key){
  dll.erase(cache[key].second);
  dll.push_front(key);
  cache[key].second = dll.begin();
}
  }
