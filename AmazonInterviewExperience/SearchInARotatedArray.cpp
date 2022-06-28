// Problem Link: https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1#

class Solution{
    public:
    int search(int A[], int l, int h, int key){
    //complete the function here

    int m;

    while(l<=h){
        m = l+(h-l)/2;

        if(A[m]==key) return m;

        if(A[l]<=A[m]){ // When A[l] to A[m] is sorted
            if(A[l]<=key && A[m]>=key) h = m-1;
            else l = m+1;
        }else if(A[m]<=A[h]){ //if A[l] to A[m] is not sorted then A[m] to A[h] is definitely sorted
            if(A[m]<=key && A[h]>=key) l = m+1;
            else h = m-1;
        }
    }

    return -1;
    }
};
