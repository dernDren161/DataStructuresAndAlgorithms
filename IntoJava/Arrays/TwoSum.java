// https://leetcode.com/problems/two-sum/

/*
    Array - Access O(1) and (Insertion and Deletion O(n))
    Linked list - Access O(n) and (Insertion and Deletion O(1))
*/
 /*
    unordered map has O(1) access time on average. and O(n) in worst case(due to collisions)
    map has O(log n) access time because it is implemented as balanced BST. and is sorted by keys.

    HashMap in Java is similar to unordered_map in C++.
    LinkedHashMap in Java maintains insertion order. Similar to unordered_map but with a linked list to maintain order.
    TreeMap in Java is similar to map in C++.
  */

/*
* Iterations
* map<int, string> myMap;
* for(auto it=myMap.begin();it!=myMap.end();it++){
*  cout << it->first << " " << it->second << endl;
* }
*
* Map<Integer, String>myMap = new HashMap<>();
* for(Map.Entry<Integer, String>entry : myMap.entrySet()){
*   sout(entry.getKey() + " " + entry.getValue());
* }
* for(Integer k : myMap.keySet()){
*   sout(k);}
* for(String v : myMap.values()){
*  sout(v);}
*
* Integer can be null. But, int cannot be null, the max it can be is default value as 0.
*
* */

//CPP
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>myMap; // k-nums[i] and v-index
        for(int i=0;i<nums.size();i++){
            if(myMap.find(target-nums[i])==myMap.end()){// don't get it.
                myMap[nums[i]]=i;
            }else{
                return {myMap[target-nums[i]],i};
            }
        }
        return {};
    }
};

//Java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> myMap = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(myMap.containsKey(target-nums[i])){
                // found the pair
                return new int[] {myMap.get(target-nums[i]),i};
            }
            myMap.put(nums[i],i);
        }
        return new int[] {};
    }
}

