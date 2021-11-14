// Problem Link: https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {

        int count = s.size();
        int l,r;

        for(int i=1;i<s.size();i++){
            // even numbers
            r = i; l = r-1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                count++;
                l--;
                r++;
            }

            r = i+1;
            l = i-1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                count++;
                l--;
                r++;
            }

        }

        return count;
    }
};
