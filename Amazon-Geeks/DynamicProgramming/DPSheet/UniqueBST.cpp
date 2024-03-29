// Problem Link: https://leetcode.com/problems/unique-binary-search-trees/submissions/
/*
  NOTE: The catalan number sequence concept is used in questions:
    1. Unique BSTs.
    2. Possible BTs from the given inorder array.
*/

class Solution {
public:
    int numTrees(int n) {

        // 1,1,2,5,14,42,132.....

        int catalan[n+1];

        catalan[0] = catalan[1] = 1;

        for(int i=2;i<=n;i++){
            catalan[i] = 0;
            for(int j=0;j<i;j++){
                catalan[i] += catalan[j] * catalan[i-j-1];
            }
        }

        return catalan[n];
    }
};
