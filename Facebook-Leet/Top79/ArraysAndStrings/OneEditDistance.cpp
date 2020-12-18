// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3015/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {

        /*
        Input: s = "ab", t = "acb"
        Output: true
        */
        int m = s.length();
        int n = t.length();

        int i=0;
        int j=0;

        int c = 0;

        while(i<m && j<n){

            if(s[i] != t[j]){
                if(c==1) return false;

                if(m>n) i++;
                else if(n>m) j++;
                else { // i.e m==n
                    i++;
                    j++;
                }

                c++;
            }else{
                i++;
                j++;
            }
        }

        while(i<m){
            c++;
            i++;
        }

        while(j<n){
            c++;
            j++;
        }

        if(c==1) return true;

        return false;
    }
};
