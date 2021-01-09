// Problem Link: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1#

class Solution{
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here
        if(N==0) return 0;

        int i=0;
        int j=0;
        int m=0;
        int s=0;

        while(j<N){
            s+=Arr[j];

            if(j-i+1<K) j++;

            else if(j-i+1 == K){
                m = max(m,s);
                s-=Arr[i];
                i++;
                j++;
            }
        }

        return m;
    }
};
