
// Problem Link: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1/?track=amazon-graphs&batchId=192
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

// matrix : given matrix
// R and C : number of rows and columns respectively



bool safe(int i, int j, int R, int C){
    return (i<R && i>=0 && j<C && j>=0);
}

int rotOranges(vector<vector<int> > &matrix, int R, int C)
{
  int count = 0;
  queue<pair<int,int>> qs;
  int r[4] = {-1,0,0,1};
  int c[4] = {0,-1,1,0};
  int truth[R][C];
  // memset(truth,0,sizeof(truth));
  for(int i = 0;i<R;i++){
      for(int j = 0;j<C;j++){
          truth[i][j] = 0;
      }
  }
  for(int i = 0;i<R;i++){
      for(int j = 0;j<C;j++){
          if(matrix[i][j] == 2){
              qs.push(make_pair(i,j));
          }
      }
  }

 int s = qs.size(); // most important point --- here used as a delimiter.
 while(!qs.empty()){
     if(s == 0){
         s = qs.size();
         count++;
     }
     s--;

     int one = qs.front().first;
     int two = qs.front().second;

     for(int i = 0;i<4;i++){

              if((safe(one+r[i],two+c[i],R,C))&&(matrix[one+r[i]][two+c[i]] == 1) && !(truth[one+r[i]][two+c[i]])){
                matrix[one+r[i]][two+c[i]] = 2;
                qs.push(make_pair(one+r[i],two+c[i]));
                truth[one+r[i]][two+c[i]] = 1;
              }
    }
     qs.pop();
 }
 for(int i =0;i<R;i++){
     for(int j = 0;j<C;j++){
         if(matrix[i][j] == 1) return -1;
     }
 }
 return count;

}



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        vector<vector<int> > matrix(R);
        for(int i=0;i<R;++i)
        {
            matrix[i].resize(C);
            for(int j=0;j<C;++j)
                cin>>matrix[i][j];
        }
        cout<<rotOranges(matrix,R,C)<<endl;
    }
    return 0;
}  // } Driver Code Ends
