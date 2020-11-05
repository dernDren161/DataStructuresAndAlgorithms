#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Problem Link: https://practice.geeksforgeeks.org/problems/print-all-possible-strings/1/?track=amazon-strings&batchId=192

// Aproach to solve the problem using bit masking.
void call(char arr[], int num){

  char temp;
  for(int i = 0; i< (1 << num-1); i++){
    string g = "";
    for(int j = num-1; j >=0; j--){
      g += arr[j];
      if(i & (1 << num-1-j)){
        g += ' ';
      }
    }
    reverse(g.begin(),g.end());
    cout << g << '$';
  }
}

int main(){
  int x = 3;
  char arr[x] = "abc";
  call(arr,x);
  cout << endl;
  return 0;
}
