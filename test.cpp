#include<bits/stdc++.h>
using namespace std;

int main(){
  map<char,int>m;
  m['a']++;
  m['b'] = 0;
  if(m.find('b')!=m.end()) cout << "Yes";
}
