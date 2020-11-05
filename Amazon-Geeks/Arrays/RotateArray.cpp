// Problem Link: https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0/?company[]=Amazon&problemStatus=unsolved&page=1&query=company[]AmazonproblemStatusunsolvedpage1

#include<bits/stdc++.h>
using namespace std;

int main() {

  int test;
  cin >> test;

  while(test--){
      int first,second;
      cin >> first >> second;
      int arr[first];
      for(int i=0;i<first;i++){
          cin >> arr[i];
      }

      queue<int> q;


      for(int i=0;i<second;i++){
          q.push(arr[i]);
      }

      for(int i=second;i<first;i++){
          arr[i-second] = arr[i];
      }

      for(int i=first-second;i<first;i++){
          arr[i] = q.front();
          q.pop();
      }

      for(int i=0;i<first;i++){
          cout << arr[i] << " ";
      }
      cout << endl;
  }

}
