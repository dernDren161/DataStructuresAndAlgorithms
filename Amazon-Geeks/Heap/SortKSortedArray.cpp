// Problem Link: https://www.youtube.com/watch?v=dYfM6J1y0mU&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=4

// This question, i.e 'Sort a K sorted array' is also called as
// 'Sort a nearly sorted array'
// nearly sorted as it is just at maximum 'k' indices apart than the originally sorted result.

#include<bits/stdc++.h>
using namespace std;

void call(vector<int>&vs, int k, int n){

  //create a min-heap of size k+1
  // @ming

  priority_queue<int,vector<int>,greater<int>> p(vs.begin(),vs.begin()+(k+1));

  int t = 0;
  for(int i=k+1;i<n;i++){
    int temp = p.top();
    vs[t++] = temp;
    p.pop();
    p.push(vs[i]);
  }

  while(!p.empty()){
    vs[t++] = p.top();
    p.pop();
  }

}
int main(){

  vector<int> A = {1,4,5,2,3,7,8,6,10,9};
  int s = 10;
  int k = 2;

  call(A,k,s);

  // print the new array thus received;
  cout << "The sorted array derived from the nearly sorted array becomes: " << endl;

  for(auto& t : A){
    cout << t << " ";
  }
  cout << endl;
  return 0;
}
