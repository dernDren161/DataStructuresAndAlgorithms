// Problem Link: https://leetcode.com/explore/interview/card/facebook/54/sorting-and-searching-3/272/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {

    int call(int l, int r){

        int res = -1;

        while(l<=r){

            int m = l + (r-l)/2;

            if(isBadVersion(m)){ // if it is bad
                res = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }

        return res;
    }
public:
    int firstBadVersion(int n) {
        /*
        Input: n = 5, bad = 4
        Output: 4
        */

        if(n==1) return (isBadVersion(n))?1:-1;

        return call(1,n);
    }
};
