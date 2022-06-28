// Problem Link: https://leetcode.com/problems/longest-palindromic-substring/submissions/
// T.C: O(n^2)
// S.C: O(1), this is the advantage of using this method.

class Solution {
public:
    string longestPalindrome(string s) {

        int start = 0;
        int end = s.size();

        int maxi = 1; // NOTE: VVVI putting maxi as INT_MIN won't work as the minimum number of palindromic substring is always at least 1.

        int l,r;

        for(int i=1;i<s.size();i++){

            // computing the even palindromic lengths
            l = i-1;
            r = i;

            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 > maxi){
                    maxi = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }

            l = i-1;
            r = i+1;

            // computing the odd palindromic lengths
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>maxi){
                    maxi = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start,maxi);
    }
};
