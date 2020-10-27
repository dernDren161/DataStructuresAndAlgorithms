// Problem Link: https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array/0#
//NOTE: This question is similar to the 'Ceil in a Sorted Array' question

//NOTE: Ceil in a Sorted Array's concept can be used to do the question 'Next character in an array'
//NOTE: Do check out this important question at: https://www.youtube.com/watch?v=X45c37QMdX0&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=12


#include<bits/stdc++.h>
using namespace std;

int call(int arr[], int n, int x){

    int l = 0; int r = n-1;
    int res = -1;
    while(l<=r){
        int m = l + (r-l)/2;

        if(arr[m] == x) return m;

        else if(arr[m] > x) r = m-1;

        else if(arr[m] < x){
            res = m;
            l = m+1;
        }
    }

    return res;
}


int main(){
    int test;
    cin >> test;

    while(test--){
        int a,b;
        cin >> a >> b;
        int arr[a];
        for(int i=0;i<a;i++){
            cin >> arr[i];
        }

        cout << call(arr,a,b) << endl;
    }
}
