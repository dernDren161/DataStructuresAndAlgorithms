// Problem Link: https://workat.tech/problem-solving/practice/matrix-rotation

/*
This question deals with if the matrix is not a squarel. It takes space but this is the correct method.
We can do the O(1) space solution only for the square matrices.
*/

vector<vector<int> > rotateMatrix(vector<vector<int> > &mat){

	int r = mat.size();
	int c = mat[0].size();

	vector<vector<int>> ans(c,vector<int> (r,0));

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			ans[j][r-1-i] = mat[i][j];
		}
	}

	return ans;


}
