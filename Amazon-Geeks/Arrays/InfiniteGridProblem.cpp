// Important: The assumption made in this question is that the length taken through the hypotenuse is same as taken
// through the x or y axes i.e 1 unit for a unit square grid

// Problem Link: https://www.geeksforgeeks.org/minimum-steps-needed-to-cover-a-sequence-of-points-on-an-infinite-grid/

#include<bits/stdc++.h>
using namespace std;

struct col{
  int a;
  int b;
};

int shortestPath(col x, col y){

  int dx = abs(x.a - y.a);
  int dy = abs(x.b - y.b);

  return max(dx,dy);
}

int call(col arr[], int s){

  int distance = 0;

  for(int i = 0; i< s-1;i++){
    distance += shortestPath(arr[i],arr[i+1]);
  }

  return distance;
}

int main(){

  col arr[] = { { 4, 6 }, { 1, 2 }, { 4, 5 }, { 10, 12 } };

  int s = sizeof(arr)/sizeof(arr[0]);

  cout << call(arr,s) << endl;

  return 0;
}
