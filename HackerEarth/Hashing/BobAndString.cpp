#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Anagram Question (Nice Algorithm!!)

//Problem Link: https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/bob-and-string-easy/description/

ll call(string& a, string& b){
    map<char,ll> m;
    for(auto&& c:a){
        m[c]++;
    }
    ll count = 0;
    for(auto&& k:b){
        auto itr = m.find(k); // if(m.find(k)!=m.end())
        if(itr != m.end()){
            itr -> second--;
            if(itr -> second == 0) m.erase(itr);
        }else{
            count++;
        }
    }
    for(auto j:m){
        count+= j.second;
    }
    return count;
}

int main(){
    ll test;
    cin >> test;
    while(test--){
        string a;
        string b;
        cin >> a;
        cin >> b;
        cout << call(a,b) << endl;
    }
    return 0;
}
