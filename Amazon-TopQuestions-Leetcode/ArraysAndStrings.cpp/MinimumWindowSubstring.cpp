// Problem Link: https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/902/

class Solution {
public:
    string minWindow(string s, string t) {

        // s = "ADOBECODEBANC", t = "ABC"

        int sSize = s.size();
        int tSize = t.size();

        if(sSize==0 || tSize==0) return "";

        string result;
        int temp = INT_MAX;

        int j=0; int i=0;

        unordered_map<char,int> tMap;
        for(auto x:t) tMap[x]++;
        int c = tMap.size();
        for(auto x:tMap) x.second = 1;

        while(j<sSize){
            auto p = tMap.find(s[j]);

            if(p != tMap.end()){ // if found
                tMap[s[j]]--;
                if(tMap[s[j]]==0) c--;
            }
            // if the value of c is zero then means we found the window
            while(c==0 && i<=j){
                // I have to store the values
                if(j-i+1 < temp){
                    temp = j-i+1;
                    result = s.substr(i,j-i+1);
                }

                if(tMap.find(s[i])!=tMap.end()){ // if s[i] is not found then just increase i as s[i] was irrelevant for us
                    tMap[s[i]]++;
                    if(tMap[s[i]]==1)c++;
                }
                i++;
            }
            j++;
        }

        return result;
    }
};
