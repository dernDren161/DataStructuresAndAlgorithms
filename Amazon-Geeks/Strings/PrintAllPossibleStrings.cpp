#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Problem Link: https://practice.geeksforgeeks.org/problems/print-all-possible-strings/1/?track=amazon-strings&batchId=192

// This question has limitation till x = 20;
// It is just to learn recursion more aptly
// The most efficient solution can be deduced using Bit Masking.
// Solution mentioned within same directory.

// Done using Recursion.
void call(char arr[], int num, char prr[], int i, int j){


  if(i == num){

    cout << prr <<'$';
    return;
  }
  // first 'either' here is that the next characters are letters only and no spaces.
  prr[j] = arr[i];
  call(arr,num,prr,i+1,j+1);

  // the second 'or' is that the next index element would be a blank space.

  prr[j] = ' ';
  prr[j+1] = arr[i];
  call(arr,num,prr,i+1,j+2);
}

int main(){
  int x = 3;
  char arr[x] = "abc";
  char prr[x];
  prr[0] = arr[0];
  call(arr,x,prr,1,1);
  cout << endl;
  return 0;
}
