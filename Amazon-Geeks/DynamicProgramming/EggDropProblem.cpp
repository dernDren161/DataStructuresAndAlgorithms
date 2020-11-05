// Problem Link: https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0#
// Why not Binary search?
// because if floors -->> 1 to 100
// and the answer is 49 then, first partition leads to floor 50 then we linearly go from 49 to 1
// Linear as in it follows binary search only but since the threshold floor is 49 so it has to go from 49 to 1
// like a linear fashion
// which gives us: 1 + 49 = 50 attempts which is too high hence discarded

#include<bits/stdc++.h>
using namespace std;
int mat[51][51];


int call(int eggs, int floors){

    if(floors == 0 || floors == 1) return floors;
    if(eggs == 1) return floors;

    if(mat[eggs][floors] != -1) return mat[eggs][floors]; 

    int m = INT_MAX;

    for(int i=1;i<=floors;i++){
        int temp = 1 + max(call(eggs-1,i-1), call(eggs,floors-i));
        m = min(temp,m);
    }
    mat[eggs][floors] = m;
    return mat[eggs][floors];
}

int main(){
    int test;
    cin >> test;
    memset(mat,-1,sizeof(mat));
    while(test--){
        int eggs;
        int floors;
        cin >> eggs >> floors;

        cout << call(eggs,floors) << endl;
    }
}
