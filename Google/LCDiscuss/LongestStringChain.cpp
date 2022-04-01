// Problem Link: https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
    static bool comp(string a, string b){
        return a.size()<b.size();
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(),words.end(),comp);

        unordered_map<string,int> myMap;
        int ans = 1;

        for(auto& w:words){
            for(int i=0;i<w.size();i++){
                string temp = w.substr(0,i) + w.substr(i+1);
                myMap[w] = max(myMap[w],(myMap.find(temp)==myMap.end())?1:myMap[temp]+1);
            }
            ans = max(ans,myMap[w]);
        }

        return ans;
    }
};
