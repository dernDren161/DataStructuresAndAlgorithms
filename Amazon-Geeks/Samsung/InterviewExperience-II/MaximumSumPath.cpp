// Problem Link: https://workat.tech/problem-solving/practice/max-path-sum-matrix

int findMaxPath(vector<vector<int>> &mat) {

	int r = mat.size();
	int c = mat[0].size();

	for(int i=1;i<r;i++){
		for(int j=0;j<c;j++){
			// if all the directions are possible
			if(j>0 && j<c-1){
				mat[i][j] += max(max(mat[i-1][j-1],mat[i-1][j+1]),mat[i-1][j]);
			}
			else if(j==0){
				mat[i][j] += max(mat[i-1][j],mat[i-1][j+1]);
			}else if(j==c-1){
				mat[i][j] += max(mat[i-1][j],mat[i-1][j-1]);
			}
		}
	}

	int maxi = 0;
	for(int i=0;i<c;i++){
		maxi = max(maxi,mat[r-1][i]);
	}

	return maxi;
}
