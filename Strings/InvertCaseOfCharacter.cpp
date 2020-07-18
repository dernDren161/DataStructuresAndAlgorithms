#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Problem Link: https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/invert-case-of-character/description/?layout=old

int main(){
    string st;
    getline(cin,st);
    ll a,b;
    cin >> a >> b;

    if(isupper(st[a-1])){
        st[a-1] = tolower(st[a-1]);
    }else{
        st[a-1] = toupper(st[a-1]);
    }

      if(isupper(st[b-1])){
        st[b-1] = tolower(st[b-1]);
    }else{
        st[b-1] = toupper(st[b-1]);
    }

    cout << st << endl;

    return 0;
}
