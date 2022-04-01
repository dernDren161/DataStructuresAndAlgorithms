// Problem Link: https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {

        unordered_map<char,vector<int>> myMap; // k-character, v-indices where k occured

        for(int i=0;i<s.size();i++){
            myMap[s[i]].push_back(i);
        }

        int ans = 0;

        for(string w:words){
            int pre = -1;
            bool flag = true;
            for(char x:w){
                auto it = upper_bound(myMap[x].begin(),myMap[x].end(),pre);

                // searches for one step upper index
                if(it == myMap[x].end()){
                    // not found
                    flag = false;
                    break;
                }else{
                    pre = *it;
                }
            }
            if(flag) ans++;
        }

        return ans;
    }
};
