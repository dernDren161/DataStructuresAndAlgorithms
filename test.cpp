#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
vector<vector<string>> wordCountEngine( const string& document )
{
  // your code goes here
  // Practice makes
  // case insensetive
  // value, string

  /*
  1. occurence in descending order
  2. if same then acc to the first
  */

  map<string,int> m;

  int n = document.size();
  string temp = "";
  for(int i =0;i<n;i++){

    if(!isalpha(document[i]) && (document[i]!='.' || document[i]!=' '))continue;
    if(document[i] != ' ' && document[i]!='.'){
      temp = temp + to_string(tolower(document[i]));
    }else if(document[i]==' ' || document[i]=='.'){
      m[temp]++;
      temp = "";
    }
  }
  // map
  vector<vector<string>> vs;
  vector<string> l;


cout<<"Map size" << m.size();



  for(auto x=m.begin();x != m.end();x++){
    l.push_back(x->first);
    l.push_back(to_string(x->second));
    vs.push_back(l);
    l.clear();
  }

  return vs;
}

int main() {
  vector<vector<string>> vs;
   vs = wordCountEngine("Practice makes perfect. you'll only get Perfect by practice. just practice!");
   cout << vs.size();
   /*for(auto x:vs){
     for(auto y:x){
       cout << y << " ";
     }
     cout << endl;
   }*/
  return 0;
}
