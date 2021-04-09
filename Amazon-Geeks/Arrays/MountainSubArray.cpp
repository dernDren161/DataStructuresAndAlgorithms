
// Problem Link:
//https://practice.geeksforgeeks.org/problems/mountain-subarray-problem/1/?track=amazon-arrays&batchId=192
// @MI (for Mountain store Index)

vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                            int q) {
    // code here
    int* less = new int[n];
    int* more = new int[n];
    int mini = 0;
    int maxi = n-1;
    less[0] = 0;
    more[n-1] = n-1;

    vector<bool> vs;

    // for lesser one
    for(int i = 1;i<n;i++){
        if(a[i] > a[i-1]){
            mini = i;
        }
        less[i] = mini;
    }


    for(int i = n-2;i>=0;i--){
        if(a[i] > a[i+1]){
            maxi = i;
        }
        more[i] = maxi;
    }

    int temp = 0;
    while(q--){
        int a = queries[temp].first;
        int b = queries[temp].second;
        temp++;
        if(more[a] >= less[b]){
            vs.push_back(true);
        }else{
            vs.push_back(false);
        }
    }

    return vs;


}
