#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void call(int num){
  int arr[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
  string str[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
  int i = 12;
  while(num > 0){
    int temp = num / arr[i];
    num = num % arr[i];
    while(temp--){
      cout << str[i];
    }
    i--;
  }
  cout << endl;
}

int main(){
  cout << "Please enter a modern Integer" << endl;
  ll num;
  cin >> num;
  call(num);
  return 0;
}
