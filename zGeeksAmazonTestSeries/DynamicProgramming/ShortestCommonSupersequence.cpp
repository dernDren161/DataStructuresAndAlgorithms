// Problem Link: https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0#

#include<bits/stdc++.h>
using namespace std;

int call(string& a, string& b, int x, int y){

    int mat[x+1][y+1];
     memset(mat,-1,sizeof(mat));

    for(int i=0;i<x+1;i++) mat[i][0] = 0;
    for(int i=0;i<y+1;i++) mat[0][i] = 0;

    for(int i=1;i<x+1;i++){
        for(int j=1;j<y+1;j++){
            if(a[i-1] == b[j-1]){
                mat[i][j] = 1 + mat[i-1][j-1];
            }else{
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }

    int temp = mat[x][y];
    if(temp == -1) return x+y;
    temp = temp + (x-temp) + (y-temp);
    return temp;

}

int main(){

    int test;
    cin >> test;

    while(test--){
        string a;
        string b;

        cin >> a >> b;

        int x = a.length();
        int y = b.length();

        cout << call(a,b,x,y) << endl;
    }

    return 0;
}
