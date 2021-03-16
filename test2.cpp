#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class lru{
	list<int> el;//Doubly linked list to store the elements
	unordered_map<int, list<int>::iterator> ref;//hashtable for storing the reference address
	int n;//hashtable for storing the refernce address
	public:
	/*Constructor to initialize the capacity of cache*/
		lru(int cap){
			n=cap;
		}
		void insert(int);
		void print();
};
/*add a value to the list if new or move the value to the front if already present*/
void lru::insert(int val){
	if(ref.find(val)==ref.end()){// if the value is not found in the list
		if(ref.size()==n){//if the cache size is equal to the capacity
			int x=el.back();
			el.pop_back();//removing the last element from the queue
            ref.erase(x); //erasing the key value pair from the hash table
		}
	}
	else{
		el.erase(ref.find(val)->second);//if present erasing it
	}
	el.push_front(val);//adding the value to the front
	ref[val]=el.begin();//storing the address in the hashtable
}
/*Iterating through the entire list and printing the elements*/
void lru::print(){
	for(auto it=el.begin();it!=el.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
int main(){
lru cache(3); //to specify the capacity
/*Refer explanation*/
cache.insert(1);//1
cache.insert(2);//2
cache.insert(3);//3
cache.insert(2);//4
cache.insert(4);//5
cache.insert(2);//6
cache.insert(5);//7
cache.print();
}
