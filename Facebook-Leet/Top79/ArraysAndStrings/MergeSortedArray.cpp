// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/309/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
        Input:
        nums1 = [1,2,3,0,0,0], m = 3
        nums2 = [2,5,6],       n = 3

        Output:
        [1,2,2,3,5,6]
        */

        // creation of a min heap

        priority_queue<int,vector<int>,greater<>> pq;

        for(int i=0;i<m;i++) pq.push(nums1[i]);
        for(int i=0;i<n;i++) pq.push(nums2[i]);

        int x = 0;

        while(!pq.empty()){
            nums1[x] = pq.top();
            pq.pop();
            x++;
        }
    }
};
