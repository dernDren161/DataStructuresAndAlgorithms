#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Problem Link: from Hackerearth theory on BitMaking

void call(char arr[], int num){

  for(int i = 0; i< (1<<num); i++){
    for(int j = 0; j< num; j++){
      if(i & (1<<j)){
        cout << arr[j] << " ";
      }
    }
    cout << endl;
  }
}

int main(){

  // char[] is equivalent to declaring a string as: string
  
  char arr[] = "abc";
  call(arr,3);
  return 0;
}
