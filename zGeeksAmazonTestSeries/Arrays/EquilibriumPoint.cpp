// Problem Link: https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1/?track=amazon-arrays&batchId=192

int equilibriumPoint(long long a[], int n) {

    int s = 0;
    for(int i=0;i<n;i++){
        s += a[i];
    }
    int left = s;
    int right = 0;

    for(int i = n-1;i>=0;i--){
        right += a[i];
        if(right == left) return i+1;
        left -= a[i];
    }

    return -1;
}
