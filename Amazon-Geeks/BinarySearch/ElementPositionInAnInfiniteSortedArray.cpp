#include<bits/stdc++.h>
using namespace std;

int callToFindIndex(int arr[], int l, int r, int x){

  while(l<=r){
    int m = l+ (r-l)/2;

    if(arr[m] == x) return m;
    else if(arr[m] < x){
      l = m+1;
    }else if(arr[m] > x){
      r = m-1;
    }
  }

  return -1;
}

vector<int> callP(int arr[], int x){
  int l = 0;
  int r = 1;
  while(x > arr[r]){
    l = r;
    r = 2*r;
  }
  vector<int>vs;
  vs.push_back(l);
  vs.push_back(r);
  return vs;
}
int main(){
  int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
                             140, 160, 170};
  vector<int>vs;
  vs = callP(arr,100);
  int l = vs[0];
  int r = vs[1];

  int ans = callToFindIndex(arr,l,r,100);
  cout << "The index of the required element is: " << ans << endl;
}
