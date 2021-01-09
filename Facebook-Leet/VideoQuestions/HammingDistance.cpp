// Problem Link: https://leetcode.com/problems/hamming-distance/submissions/

class Solution {
public:
    int hammingDistance(int x, int y) {

        int c = 0;

        while(x || y){

            if(x%2 != y%2) c++;

            x/=2;
            y/=2;
        }

        return c;
    }
};
