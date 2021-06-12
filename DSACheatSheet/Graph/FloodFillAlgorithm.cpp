// Problem Link: https://leetcode.com/problems/flood-fill/submissions/
// TC : O(m*n)

class Solution {
public:

    int previous;

    void callDFS(int i, int j, vector<vector<int>>& image, int c, int row, int col){

        if(i<0 || i>=row || j<0 || j>=col) return;
        if(image[i][j] == c) return;
        if(image[i][j] != previous) return;

        image[i][j] = c;

        // r,d,l,u
        callDFS(i,j+1,image,c,row,col);
        callDFS(i+1,j,image,c,row,col);
        callDFS(i,j-1,image,c,row,col);
        callDFS(i-1,j,image,c,row,col);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        if(image[sr][sc]==newColor) return image;

        int r = image.size();
        int c = image[0].size();

        previous = image[sr][sc];

        callDFS(sr,sc,image,newColor,r,c);

        return image;
    }
};
