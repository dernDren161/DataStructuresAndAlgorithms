// Problem Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#

/*
map ----> Uses self-balancing BST internally
unordered_map ----> Uses Hash table internally

map ----> Has (log n) T.C for search, insert and delete, almost
unordered_map -----> Has O(1) as average T.C and O(n) if there is hash collision

map ----> sorts the elements w.r.t its elements while storing
unordered_map ----> no sorting is done whatsoever, hence preserving the order of insertion.

*/
vector <int> max_of_subarrays(int *arr, int n, int k){
    // your code here

    if(n==0 || k==0) return {};

    unordered_map<int,int>m;
    priority_queue<int> pq;
    int i=0;
    int j=0;

    vector<int> res;

    while(j<n){

        pq.push(arr[j]);

        if(j-i+1 < k){
            m[arr[j]]++;
            j++;
        }

        else if(j-i+1 == k){
            res.push_back(pq.top());
            m[arr[i]]--;
            m[arr[j]]++;
            i++;
            j++;

            // What if the ith element is the maximum for window k ?

            while(!pq.empty() && m[pq.top()]==0) pq.pop();
        }
    }

    return res;
}
