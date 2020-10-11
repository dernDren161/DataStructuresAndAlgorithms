#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int call(int l, int r, int x, int* arr){

    while(l<=r){
      int m = l + (r-l)/2;

      if(arr[m] == x) return m;

      else if(arr[m] > x) r = m-1;

      else l = m+1;
    }

    return -1;
}

int main(){
  int arr[] = {1,6,8,90,100,654,789};

  int n = sizeof(arr)/sizeof(arr[0]);

  cout << call(0,n-1,789,arr) << endl;

  return 0;
}
