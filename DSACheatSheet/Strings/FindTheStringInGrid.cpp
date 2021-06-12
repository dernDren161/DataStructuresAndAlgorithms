// Problem Link: https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1

class Solution {
public:

    int row[8]={0,1,1,1,0,-1,-1,-1};
    int col[8]={1,1,0,-1,-1,-1,0,1};

    bool safe(int newRow, int newCol, int r, int c){
        return newRow>=0 && newRow<r && newCol>=0 && newCol<c;
    }

    bool call(vector<vector<char>> grid, int i, int j, int r, int c, string word){

        if(grid[i][j] != word[0]) return false;

        int newRow,newCol;

        for(int x=0;x<8;x++){
            newRow = i + row[x];
            newCol = j + col[x];

            int k;

            for(k=1;k<word.size();k++){
                if(!safe(newRow,newCol,r,c)) break;
                if(grid[newRow][newCol] != word[k]) break;

                newRow += row[x];
                newCol += col[x];
            }

            if(k==word.size()) return true;
        }
        return false;
    }

	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here

	    int r = grid.size();
	    int c = grid[0].size();

	    vector<vector<int>> res;

	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            if(call(grid,i,j,r,c,word)){
	                res.push_back({i,j});
	            }
	        }
	    }
	}
};
