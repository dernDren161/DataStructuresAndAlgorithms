// Problem Link: https://leetcode.com/problems/valid-mountain-array/submissions/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

      int N = arr.size();
    if(N <3)
        return false;
    int i = 0;

    while(i < N-1 && arr[i] < arr[i + 1])
        i++;

    if(i == 0 || i == N - 1)
        return false;

    while(i < N-1 && arr[i] > arr[i + 1])
        i++;

    if(i == N - 1)
        return true;
    return false;
    }
};
