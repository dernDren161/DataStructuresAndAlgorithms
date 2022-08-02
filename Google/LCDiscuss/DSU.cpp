// Problem Link: https://www.codechef.com/problems/FIRESC/

#include<bits/stdc++.h>
using namespace std;

void initializeArr(int arr[], int n, int size[]){

    for(int i=0;i<n+1;i++){
        arr[i] = i;
        size[i] = 1;
    }
}

int findRoot(int n, int arr[], int size[]){

    while(n!=arr[n]){
        arr[n] = arr[arr[n]];
        n = arr[n];
    }

    return n;
}

void unionS(int a, int b, int size[], int arr[]){
    int rootA; int rootB;
    rootA = findRoot(a,arr,size);
    rootB = findRoot(b,arr,size);

    if(size[rootA]<size[rootB]){
        arr[rootA] = arr[rootB];
        size[rootB] += size[rootA];
    }else{
        arr[rootB] = arr[rootA];
        size[rootA] += size[rootB];
    }
}

int main() {

    int test;
    cin >> test;
    while(test--){
        int n; int m;
        cin >> n >> m;
        int arr[n+1];
        int size[n+1];
        initializeArr(arr,n,size);
        while(m--){
            int a; int b;
            cin >> a >> b;
            unionS(a,b,size,arr);
        }
        unordered_map<int,int>myMap;
        for(int i=1;i<n+1;i++)myMap[arr[i]]++;
        cout << myMap.size() << " ";
        int ans = 1;
        for(auto it:myMap){
            ans = (ans * it.second)%1000000007;
        }
        cout << ans%1000000007 << endl;
    }
}
