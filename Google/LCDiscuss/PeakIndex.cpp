// Problem Link: https://leetcode.com/explore/interview/card/google/63/sorting-and-searching-4/3084/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int n = arr.size();
        int l = 0; int r = n-1;

        while(l<=r){

            int m = l + (r-l)/2;

            if((m==0 || arr[m]>=arr[m-1]) && (m==n-1 || arr[m]>=arr[m+1])) return m;
            else if(m>0 && arr[m]<=arr[m-1]) r = m-1;
            else l = m+1;
        }

        return -1;
    }
};
