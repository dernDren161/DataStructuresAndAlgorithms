// Problem Link: https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

#include<bits/stdc++.h>
using namespace std;


int call(int arr[], int n){

    int l[n];
    int r[n];
    l[0] = arr[0];
    r[n-1] = arr[n-1];

    for(int i=1;i<n;i++){
        l[i] = max(l[i-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        r[i] = max(r[i+1],arr[i]);
    }

    int t = 0;
    for(int i=0;i<n;i++){

            t = t + (min(l[i],r[i]) - arr[i]);


    }

    return t;

}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        cout << call(arr,n) << endl;
    }
}
