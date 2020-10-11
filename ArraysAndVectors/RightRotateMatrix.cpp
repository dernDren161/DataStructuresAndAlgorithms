// Problem Link: https://www.interviewbit.com/problems/rotate-matrix/

// It's good if you can memorize the first "transpose" creating code after thoroughly understanding it for fast programming (which I have)

void Solution::rotate(vector<vector<int> > &A) {

    // First find the transpose of the given matrix

    // This is my standard solution for matrix rotation
    int x = 0;
    int y = 0;
    int n = A.size();

    while(x<n && y<n){
      int i = x+1;
      int j = y+1;
        while(i<n && j<n){
          swap(A[x][i],A[j][y]);
          i++;
          j++;
        }
        x++;
        y++;
    }

    // Now reverse the matrix elements for Right Rotate

    int l = 0;
    int r = n-1;

    while(l<r){
      int i = 0;
        while(i<n){
          swap(A[i][l],A[i][r]);
          i++;
        }
        l++;
        r--;
    }
}
