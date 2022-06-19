// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-swaps-1624449643/0/?track=GTS-ARRAY&batchId=397#

int minSwaps(int n,vector<int> A, vector<int> B){

       int a; int b; a = A[0]; b = B[0];
       vector<int>nSwaps(4,0);
       vector<bool>permit(4,true);

       for(int i=0;i<n;i++){
           if(A[i]!=a){
               if(B[i]!=a)permit[0]=false;
               nSwaps[0]++;
           }

           if(B[i]!=a){
               if(A[i]!=a)permit[1]=false;
               nSwaps[1]++;
           }

           if(A[i]!=b){
               if(B[i]!=b)permit[2] = false;
               nSwaps[2]++;
           }

           if(B[i]!=b){
               if(A[i]!=b)permit[3] = false;
               nSwaps[3]++;
           }
       }

       int ans = INT_MAX;
       for(int i=0;i<4;i++){
           if(permit[i]==true){
               ans = min(ans,nSwaps[i]);
           }
       }

       return (ans==INT_MAX)?-1:ans;
   }
