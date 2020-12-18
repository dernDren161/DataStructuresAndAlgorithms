// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3008/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        vector<int> vs(256,-1);

        int start = 0;

        int ans = 0;

        for(int i=0;i<n;i++){

            start = max(start,vs[s[i]]+1);
            ans = max(ans,i-start+1);

            vs[s[i]] = i;
        }

        return ans;
    }
};
