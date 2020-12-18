// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3017
// NOTE: This question uses the 'Sliding Window algorithmic pattern'


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        /*
        Input: s = "eceba", k = 2
        Output: 3
        */

        int n = s.length();

        int l = 0;

        set<char> window;
        map<char,int> m;

        int res = 0;

        for(int i=0;i<n;i++){

            window.insert(s[i]);
            m[s[i]]++;

            while(window.size()>k){
                m[s[l]]--;
                if(m[s[l]] == 0) {
                    window.erase(s[l]);
                    m.erase(s[l]);
                }
                l++;
            }
            res = max(res,(i-l)+1);
        }
        return res;

    }
};
