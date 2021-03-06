#include<bits/stdc++.h>
using namespace std;

int call(string& a, string& b, int x, int y){

    int mat[x+1][y+1];

    for(int i=0;i<x+1;i++) mat[i][0] = 0;
    for(int i=0;i<y+1;i++) mat[0][i] = 0;

    for(int i=1;i<x+1;i++){
        for(int j=1;j<y+1;j++){
            if((a[i-1] == b[j-1]) && (i != j)){    // NOTE: 'i != j' is the only changing factor in this code.
                mat[i][j] = 1 + mat[i-1][j-1];
            }else{
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }

    return mat[x][y];
}

int main(){
    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;
        string a;
        cin >> a;


        cout << call(a,a,n,n) << endl;
    }
}
