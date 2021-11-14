
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

  NOTE: Printing the Largest common substring is different than this one.

  modifications:
    int row,col;
    int len = INT_MIN;

    for(int i=1;i<a+1;i++){
    for(int j=1;j<b+1;j++){
      if(s[i-1]==t[j-1]){
        mat[i][j] = 1+mat[i-1][j-1];
        if(len<mat[i][j]){
        len = mat[i][j];
        row = i; col = j;
      }
    }
  }
  }
  string result = "";

    while(len--){
      result = s[row-1]; // or can also do t[col-1] since both are equal
      row--;
      col--; // Just moving diagonally upwards
  }

  return result;
*/
string& call(string& s1, string& s2, ll a, ll b){

    ll mat[a+1][b+1];

    for(ll i=0;i<a+1;i++) mat[i][0] = 0;
    for(ll i=0;i<b+1;i++) mat[0][i] = 0;

    for(ll i=1;i<a+1;i++){
        for(ll j=1;j<b+1;b++){
            if(s1[i-1] == s2[j-1]) mat[i][j] = 1 + mat[i-1][j-1];
            else{
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }

    string res = "";



        while(a > 0 && b > 0){
            if(s1[a-1] == s2[b-1]){
                res += s1[a-1];
                a--; b--;
            }
            else if(mat[a-1][b] > mat[a][b-1]) a--;
            else b--;
        }


    reverse(res.begin(),res.end());

    return res;
}

int main(){
    ll test;
    cin >> test;
    while(test--){
        ll a=6;
        ll b=7;

        string s1="AGGTAB";
        string s2="GXTXAYB";


        cout << call(s1,s2,a,b) << endl;
    }
}
