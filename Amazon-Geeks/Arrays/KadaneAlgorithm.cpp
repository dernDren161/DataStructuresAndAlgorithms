// Problem Link:
//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/0/?track=amazon-arrays&batchId=192

int maxSubarraySum(int arr[], int n){

    int localMax = arr[0];
    int maxi = arr[0];

    for(int i=1;i<n;i++){

        localMax = max(localMax + arr[i], arr[i]);

        maxi = max(maxi,localMax);
    }

    return maxi;

}
