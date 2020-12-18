// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3014/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        /*
        Input: strs = ["eat","tea","tan","ate","nat","bat"]
        Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
        */

        map<map<char,int>,vector<string>> masterMap;

        for(string x:strs){
            int s = x.size();
            map<char,int> m;
            vector<string> tVect;

            for(char c:x){
                m[c]++;
            }// creation of a map
        auto p = masterMap.find(m);

            if(p != masterMap.end()){ // found
                p->second.push_back(x);
            }else{
                tVect.push_back(x);
                masterMap.insert({m,tVect});
            }
        }

        vector<vector<string>> res;

        for(auto g=masterMap.begin(); g!=masterMap.end(); g++){
            res.push_back(g->second);
        }

        return res;
    }
};
