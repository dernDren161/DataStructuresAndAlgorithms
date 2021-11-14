// Problem Link: https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2969/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    /*
        1,2,3   7,4,1   1,4,7
        4,5,6   8,5,2   2,5,8
        7,8,9   9,6,3   3,6,9

    */

        int n = matrix.size(); // as an nXn matrix is given

        int x=0;
        int y=0;
        int i=0;
        int j=0;

        while(x<n && y<n){// here x is for rows and y is for columns
            i = x+1;
            j = y+1;
                while(i<n && j<n){
                    swap(matrix[x][i],matrix[j][y]);
                    i++;j++;
                }
            x++;y++;
        }// Transpose of the matrix


        int l;
        int r;

        for(int c=0;c<n;c++){

            l=0;
            r=n-1;

            while(l<r){
                swap(matrix[c][l],matrix[c][r]);
                l++;
                r--;
            }
        }

        return;

    }
};
