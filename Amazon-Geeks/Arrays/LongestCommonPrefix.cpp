// Problem Link: https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0#

#include<bits/stdc++.h>
using namespace std;

// NOTE: The string array is like a 2D matrix
 
string call(int n, string arr[]){

    string result = "";

    sort(arr,arr+n);

    int firstSize = arr[0].length();

    for(int i=0;i<firstSize;i++){
        if(arr[0][i] == arr[n-1][i]){
            result += arr[0][i];
        }else break;
    }

    if(result.empty()){
        result = "-1";
    }
    return result;
}

int main(){
    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;
        string arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        cout << call(n,arr) << endl;
    }

    return 0;
}
