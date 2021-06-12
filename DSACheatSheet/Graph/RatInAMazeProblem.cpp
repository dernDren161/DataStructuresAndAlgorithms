// Problem Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

// T.C : O(n^2)^4, i.e n^2 to the power 4 i.e n^8
// Auxillary space: O(L*x), where L is the length of the valid path, and x is the number of such paths
// The Auxillary space is basically for the vector<string> ans which is (L*x)

class Solution{
    public:
    vector<string> ans;

    void callDFS(int i, int j,vector<vector<int>>& mat,int n, string s){

        if(i<0 || i>=n || j<0 || j>=n || mat[i][j]==0) return;


        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }

        mat[i][j] = 0;

        // RDLU

        callDFS(i,j+1,mat,n,s+'R');
        callDFS(i+1,j,mat,n,s+'D');
        callDFS(i,j-1,mat,n,s+'L');
        callDFS(i-1,j,mat,n,s+'U');

        // Backtracking
        mat[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here

        ans.clear();



        if(m[0][0]==0 || m[n-1][n-1]==0) return ans;

        string s = "";

        callDFS(0,0,m,n,s);

        sort(ans.begin(),ans.end());

        return ans;
    }
};
