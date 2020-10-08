// Problem Link: https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/?track=amazon-arrays&batchId=192

ll FindMaxSum(ll arr[], ll n)
{
    ll a[n+1];

    if(n == 0) return 0;
    if(n == 1) return arr[0];
    if(n == 2) return max(arr[0],arr[1]);

    a[0] = 0;
    a[1] = arr[0];
    a[2] = max(arr[0],arr[1]);



    for(ll i=3;i<n+1;i++){
        a[i] = max((arr[i-1] + a[i-2]),(a[i-1]));
    }

    return a[n];

}
