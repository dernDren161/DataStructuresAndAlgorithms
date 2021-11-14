// Problem Link: https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/480/

class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char,int> myMap;

        for(auto x:s) myMap[x]++;

        for(int i=0;i<s.size();i++){
            if(myMap[s[i]]==1) return i;
        }

        return -1;
    }
};
