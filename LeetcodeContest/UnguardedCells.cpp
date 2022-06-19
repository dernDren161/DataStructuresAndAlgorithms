// Problem Link: https://leetcode.com/contest/biweekly-contest-77/problems/count-unguarded-cells-in-the-grid/

class Solution {
public:

    bool isSafe(int r, int c, int m, int n){
        return r>=0 && c>=0 && r<m && c<n;
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<vector<char>>vs(m,vector<char>(n,'.'));

        for(vector<int>x:guards){
            int r = x[0];
            int c = x[1];
            vs[r][c] = 'p';
        }

        for(vector<int>x:walls){
            int r = x[0];
            int c = x[1];
            vs[r][c] = 'p';
        }

        // R,D,L,U
        int rowM[4] = {0,1,0,-1};
        int colM[4] = {1,0,-1,0};

        for(vector<int>x:guards){
            int r = x[0];
            int c = x[1];

            for(int k=0;k<4;k++){
                int newRow = r + rowM[k];
                int newCol = c + colM[k];

                while(isSafe(newRow,newCol,m,n) && vs[newRow][newCol]!='p'){
                    vs[newRow][newCol] = 'q'; // NOTE: VVVImp
                    newRow = newRow + rowM[k];
                    newCol = newCol + colM[k];
                }
            }
        }

        int ans = 0;
        for(int i=0;i<vs.size();i++){
            for(int j=0;j<vs[i].size();j++){
                if(vs[i][j]=='.')ans++;
            }
            cout << endl;
        }

        return ans;
    }
};
