//roblem Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

class Solution{

	public:
	int call(string& str1, string& str2, int x, int y){

	    int mat[x+1][y+1];

	    // this is initialization
	    // anaogous to the 'base case' while in recursion

	    for(int i=0;i<x+1;i++) mat[i][0]=0;
	    for(int i=0;i<y+1;i++) mat[0][i]=0;

	    for(int i=1;i<x+1;i++){
	        for(int j=1;j<y+1;j++){

	            if(str1[i-1] == str2[j-1]) {
	                mat[i][j] = 1 + mat[i-1][j-1];
	            }else{
	                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
	            }
	        }
	    }

	    int temp = mat[x][y];
	    int adding = x - temp;
	    int subtracting = y - temp;

	    return adding+subtracting;

	}

	public:
	int minOperations(string str1, string str2)
	{
	    int x = str1.length();
	    int y = str2.length();

	    return call(str1,str2,x,y);
	}
};
