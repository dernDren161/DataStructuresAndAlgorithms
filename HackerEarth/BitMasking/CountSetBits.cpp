// The indexiing is from 1 instead of 0

#include<bits/stdc++.h>
using namespace std;

int call(int myNumber, int left, int right){

    int temp = ((1 << right)-1) ^ ((1 << (left-1))-1);

    int send = (myNumber & temp);
    int count = 0;

    while(send){
        // This particular algorithm is called: Brian Kernighan’s Algorithm
        // Time complexity of this algo is: O(logn)
        send = send & (send-1);
        count++;
    }

    return count;
}

int main(){

  int myNumber = 135;
  int left = 2;
  int right = 5;

  cout << call(myNumber,left,right) << endl;

  return 0;
}
