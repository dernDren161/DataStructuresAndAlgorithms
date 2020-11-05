// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions/0#

#include<bits/stdc++.h>
using namespace std;


// NOTE: This is the same exact solution for the question: 'Minimum number of insertions to make the string palindrome'
// Just that the length of the string increases by the number of extra insertions needed(x), in string (s)
// Which now makes the length as: x+s

int call(string& s, int n, string& a){

    int mat[n+1][n+1];

    for(int i=0;i<n+1;i++) mat[i][0] = 0;
    for(int i=0;i<n+1;i++) mat[0][i] = 0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){

            if(s[i-1] == a[j-1]){
                mat[i][j] = 1 + mat[i-1][j-1];
            }else{
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }

    int temp = mat[n][n];
    return (n-temp);

}

int main(){
    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string a;
        a = s;
        reverse(a.begin(),a.end());
        cout << call(s,n,a) << endl;
    }
    return 0;
}
