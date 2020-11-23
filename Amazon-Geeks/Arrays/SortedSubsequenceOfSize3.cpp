// Problem Link:
//https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/?track=amazon-arrays&batchId=192

vector<int> call(int* less, int* more, int n, vector<int> &arr){


    less[0] = -1;
    more[n-1] = -1;
    int mini = 0;
    int maxi = n-1;

    // for computing the lesser array
    for(int i=1;i<n;i++){
        // for -1
        if(arr[i] <= arr[mini]){
            less[i] = -1;
            mini = i;
        }else{
            less[i] = mini;
        }
    }

    // for computing the larger array
    for(int i = n-2;i>=0;i--){
        if(arr[i] >= arr[maxi]){
            more[i] = -1;
            maxi = i;
        }else{
            more[i] = maxi;
        }
    }

    vector<int> vs;
    vs.clear();


    for(int i=1;i<n;i++){
        if((less[i] >=0) && (more[i] >= 0)){

          // This point is very important.
           vs.push_back(arr[less[i]]);
            vs.push_back(arr[i]);
            vs.push_back(arr[more[i]]);
            return vs;
        }
    }


    return vs;


}

vector<int> find3Numbers(vector<int> arr, int N) {

    int *less = new int[N];
    int *more = new int[N];


    return call(less,more,N,arr);

}
