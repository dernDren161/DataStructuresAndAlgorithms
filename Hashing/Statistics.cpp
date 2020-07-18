#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,string> person;
map<string,ll> c;

// Problem Link: https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/statistics-2/description/

int main(){
    ll test;
    cin >> test;
    while(test--){
        string a;
        string b;
        cin >> a >> b;
        if(person.find(a)==person.end()){
            person[a] = b;
            c[b]++;
        }
    }
    ll maxi = 0;
    string see;
    for(pair<string,ll> s:c){
        if(s.second>maxi){
            maxi = s.second;
            see = s.first;
        }
    }
    cout << see << endl;
    cout << c["football"] << endl;
}
