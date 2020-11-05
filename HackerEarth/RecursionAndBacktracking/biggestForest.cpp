#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char arr[1000][1000];
ll truth[1000][1000]={0};

// Problem Link: https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/biggest-forest-700592dd/

ll call(ll i, ll j,ll test){
    ll co =1;
truth[i][j] = 1;
if((arr[i][j+1]=='T')&&(j+1<test)&&(truth[i][j+1]==0)) co+=call(i,j+1,test);
if((arr[i+1][j]=='T')&&(i+1<test)&&(truth[i+1][j]==0)) co+=call(i+1,j,test);
if((arr[i][j-1]=='T')&&(j-1>=0)&&(truth[i][j-1]==0)) co+=call(i,j-1,test);
if((arr[i-1][j]=='T')&&(i-1>=0)&&(truth[i-1][j]==0)) co+=call(i-1,j,test);
return co;
}

int main(){
    ll test;
    cin >> test;
    for(ll i=0;i<test;i++){
        cin >> arr[i];
    }
    ll ans=0;
    for(ll i=0;i<test;i++){
        for(ll j=0;j<test;j++){
            if((arr[i][j]=='T') && (truth[i][j]==0)){
                ans = max(call(i,j,test),ans);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
