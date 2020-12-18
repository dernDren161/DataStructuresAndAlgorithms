// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/289

class Solution {

    bool call(int l, int r, string& s){
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else{
                return false;
            }
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int r = s.length()-1;
        int l = 0;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else{
                if(call(l+1,r,s)) return true;
                else if(call(l,r-1,s)) return true;
                return false;
            }
        }
        return true;
    }
};
