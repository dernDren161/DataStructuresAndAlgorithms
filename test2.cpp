// f<----->r

class LRU{
	list<int> recent;
	unordered_map<int,pair<int,list<int> :: iterator>> cache;
	int c;

	LRU(int c){
		this -> c = c;
	}

	void moveForward(int k){
		recent.erase(cache[k].second);
		recent.push_front(k);
		cache[k].second = recent.begin();
	}

	int get(int k){
		if(cache.find(key)!= cache.end()){
			moveForward(key);
			return cache[k].first;
		}
	}

	void put(int k, int v){
			if(cache.find(key)!=cache.end()){
				moveForward(key);
				cache[k].first = v;
			}else if(cache.size()==this->c){
				int temp = recent.back();
				recent.pop_back();
				recent.push_front(k);
				cache[k] = {k,make_pair(v,recent.begin())};
			}else{
				recent.push_front(key);
				cache[k] = {}
			}
	}
};
