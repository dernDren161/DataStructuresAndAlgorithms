// Problem Link: https://leetcode.com/problems/find-original-array-from-doubled-array/
// T.C: O(k log k) + O(n)
// where k is the number of distinct elements in the array

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {

        int n = changed.size();

        if(n%2 != 0) return {};

        unordered_map<int,int> myMap; // k-number, v-occurences

        for(int x:changed) myMap[x]++;

        vector<int>temp;
        for(auto it:myMap) temp.push_back(it.first);

        sort(temp.begin(),temp.end());

        vector<int> ans;

        for(int x:temp){

            if(myMap[x]>myMap[2*x]) return {};

            for(int i=0;i<myMap[x];i++){
                if(myMap[x]>0){ // for testcase {0,0,0,0} the answer is {0,0}
                ans.push_back(x);
                myMap[2*x]--;
                }
            }
        }

        return ans;
    }
};
