class Solution {

    vector<int> vs;
    public:

    int callDP(int n, int sum, vector<int>& vs){

        int mat[n+1][sum+1];

        for(int i=0;i<sum+1;i++)mat[0][i]= INT_MAX-1;
        for(int i=1;i<n+1;i++) mat[i][0] = 0;

        for(int i=0;i<sum+1;i++){
            if(i%vs[0]==0)mat[1][i]=i/vs[0];
            else mat[1][i] = INT_MAX-1;
        }

        for(int i=2;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(j>=vs[i-1]){
                    mat[i][j] = min(1+mat[i][j-vs[i-1]],mat[i-1][j]);
                }else{
                    mat[i][j] = mat[i-1][j];
                }
            }
        }

        return mat[n][sum];
    }
    void call(int n){
        if(n==0) return;

        for(int i=1;i<=n;i++){
            int temp = sqrt(i);
            if(temp*temp==i)vs.push_back(i);
        }
        return;
    }
    int numSquares(int n) {

        call(n); // getting the perfect squares

        int num = vs.size();

       return callDP(num,n,vs);
    }
};
