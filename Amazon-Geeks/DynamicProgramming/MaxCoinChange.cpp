// Problem Link:
//https://practice.geeksforgeeks.org/problems/coin-change2448/1#

class Solution
{
  public:
    long long int call(int S[], int m, int n){

        long long int mat[m+1][n+1];

        /*  if (n == 0)
        return 1;

    // If n is less than 0 then no  
    // solution exists
    if (n < 0)
        return 0;

    // If there are no coins and n
    // is greater than 0, then no
    // solution exist
    if (m <=0 && n >= 1)
        return 0; */
        for(long long int i = 0;i<n+1;i++) mat[0][i] = 0;
        for(long long int i = 1;i<m+1;i++) mat[i][0] = 1;

        for(long long int i=1;i<m+1;i++){
            for(long long int j=1;j<n+1;j++){

                if(j>=S[i-1]){
                    // unbounded knapSack
                    mat[i][j] = mat[i][j-S[i-1]] + mat[i-1][j];
                }
                else mat[i][j] = mat[i-1][j];
            }
        }

        return mat[m][n];
    }

  public:
    long long int count( int S[], int m, int n )
    {

        return call(S,m,n);
    }
};
