// Problem Link: https://practice.geeksforgeeks.org/problems/number-of-palindromic-paths-in-a-matrix/0

#include<bits/stdc++.h>
using namespace std;
char mat[10][10];
int cnt;

bool check(int i, int j, int r, int c){
    return (i<r && j<c && i>=0 && j>=0);
}

void call(int r, int c, string temp, int i, int j){

    temp += mat[i][j];

    if((i==r-1)&&(j==c-1)){
        if(temp == string(temp.rbegin(),temp.rend())){
            cnt++;
        }
        return;
    }

    if(check(i,j,r,c)){
        call(r,c,temp,i,j+1); // going right
        call(r,c,temp,i+1,j); // going left
    }
    return;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int r;
        int c;
        cin >> r >> c;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin >> mat[i][j];
            }
        }
        cnt = 0;
        string temp = "";
        call(r,c,temp,0,0);
        cout << cnt << endl;
        memset(mat,0,sizeof(mat));
    }

    return 0;

}
