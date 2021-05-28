// Memoization helps reduce the recursive time complexity of O(2^n) to O(n^2)

// Note: For MCM memoization: (i=1 and j=n-1) k till n-2 or k till < j
// For Palindrome patitioning: (i=0 and j=n-1) k from 0 to n-2 or k till < j(same as above, this part)


#include<bits/stdc++.h>
using namespace std;
int mat[30][30];

int call(int arr[], int i, int j){

    if(i>=j) return 0;

    if(mat[i][j] != -1) return mat[i][j];

    int mn = INT_MAX;

    for(int k=i;k<j;k++){
        int temp = call(arr,i,k) + call(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];

        if(temp<mn) mn = temp;
    }

    mat[i][j] = mn;
    return mat[i][j];
}

int main(){
    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        memset(mat,-1,sizeof(mat));
        cout << call(arr,1,n-1) << endl;
    }
}
