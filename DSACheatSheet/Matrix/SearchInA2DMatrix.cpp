// Problem Link: https://leetcode.com/problems/search-a-2d-matrix/solution/
// NOTE: The time complexity of this solution is O(log m*n)
// Auxillary Space complexity is: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = (m*n)-1;

        while(l<=r){
            int m = l+(r-l)/2;

            int x = m/n;
            int y = m%n;

            if(matrix[x][y]==target) return true;

            else if(matrix[x][y]<target){
                l = m+1;
            }else{
                r = m-1;
            }
        }

        return false;
    }
};
