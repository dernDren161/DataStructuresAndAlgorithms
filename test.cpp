class LRUCache {
    list<int> recent;
    unordered_map<int, pair<int, list<int>:: iterator>> cache; //{key, {value, iterator to key in recent}}
    unsigned int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void moveForward(int key) {
        recent.erase(cache[key].second);
        recent.push_front(key);
        cache[key].second = recent.begin();
    }

    int get(int key) {
        if(cache.find(key) != cache.end()) {
            moveForward(key);
            return cache[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
       if(cache.find(key) != cache.end()) {
           moveForward(key);
           cache[key].first = value;
       } else if(cache.size() == this->capacity) {
           recent.push_front(key);
           int toDelete = recent.back();
           recent.pop_back();
           cache.erase(toDelete);
           cache.insert({key, make_pair(value, recent.begin())});
       } else if(cache.size() < this->capacity) {
           recent.push_front(key);
           cache.insert({key, make_pair(value, recent.begin())});
       }
    }
};
