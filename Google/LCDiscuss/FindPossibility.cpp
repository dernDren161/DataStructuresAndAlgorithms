// Discuss Link: https://leetcode.com/discuss/interview-question/1568857/Google-or-Phone-or-Is-path-possible-less-than-threshold

#include<bits/stdc++.h>
using namespace std;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
bool isPossible(int x,int y,int rows,int cols){
	if(x < 0 or x >= rows or y < 0 or y >= cols) return 0;
	return 1;
}

bool dfs(vector<vector<int> > &grid,int x,int y,int &rows,int &cols,int threshold,vector<vector<int> > &visited){
	if(x == rows-1 and y == cols-1){
		return 1;
	}
	visited[x][y] = 1;
	for(int k = 0;k < 4;k++){
		int nx = x + dir[k][0];
		int ny = y + dir[k][1];
		if(isPossible(nx,ny,rows,cols) and abs(grid[nx][ny]-grid[x][y]) <= threshold and !visited[nx][ny]){
			int ans = dfs(grid,nx,ny,rows,cols,threshold,visited);
			if(ans) return 1;
		}
	}
	return 0;
}

int main(){
	int rows,cols,threshold;
	cin>>rows>>cols>>threshold;
	vector<vector<int> > grid(rows,vector<int>(cols));
	vector<vector<int> > visited(rows,vector<int>(cols,0));
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>grid[i][j];
		}
	}
	bool ans = dfs(grid,0,0,rows,cols,threshold,visited);
	if(ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
