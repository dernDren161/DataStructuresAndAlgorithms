// Problem Link: https://www.geeksforgeeks.org/find-maximum-product-of-a-triplet-in-array/

class Solution{
public:
    long long maxProduct(int arr[], int n) {

        // Arr[] = {10, 3, 5, 6, 20}

        int maxLeft[n];
        int minLeft[n];
        int maxRight[n];
        int minRight[n];

        maxLeft[0] = -1;
        maxRight[n-1] = -1;
        minLeft[0] = -1;
        minRight[n-1] = -1;

        long long answer = INT_MIN;

        int maxi = arr[0];
        int mini = arr[0];


        // GOING Left
        for(int i=1;i<n;i++){

            maxLeft[i] = maxi;
            if(arr[i]>maxi){
                maxi = arr[i];
            }

            minLeft[i] = mini;
            if(arr[i]<mini){
                mini = arr[i];
            }
        }

        maxi = arr[n-1];
        mini = arr[n-1];


        // GOING RIGHT
        for(int i=n-2;i>=0;i--){

            maxRight[i] = maxi;
            if(arr[i]>maxi){
                maxi = arr[i];
            }

            minRight[i] = mini;
            if(arr[i]<mini){
                mini = arr[i];
            }
        }

        long long a1;
        long long a2;

        for(int i=1;i<n-1;i++){

            a1 = (long long)max((long long)maxLeft[i]*arr[i]*maxRight[i],(long long)minLeft[i]*arr[i]*minRight[i]);
            a2 = (long long)max((long long)minLeft[i]*arr[i]*maxRight[i],(long long)maxLeft[i]*arr[i]*minRight[i]);

            answer = max(answer,max(a1,a2));

        }

        return answer;


    }
};
