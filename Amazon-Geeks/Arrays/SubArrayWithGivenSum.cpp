// Problem Link:
//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/0/?track=amazon-arrays&batchId=192

// This question is only based for non-negative numbers as inputs.
vector<int> subarraySum(int arr[], int n, int s){

    int a = 0;

    int x = 0;

    vector<int> vs;
    for(int i=0;i<n;i++){

        x += arr[i];

         while(x > s){
            x = x - arr[a];
            a++;
        }

        if(x == s){
            vs.push_back(a+1);
            vs.push_back(i+1);
            return vs;
        }
    }

    vs.push_back(-1);

    return vs;
}
