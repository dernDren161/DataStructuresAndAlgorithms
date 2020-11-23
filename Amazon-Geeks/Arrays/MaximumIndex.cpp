// Problem Link:
//https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1/?track=amazon-arrays&batchId=192

int maxIndexDiff(int arr[], int n)
{

    int* less = new int[n];
    int* more = new int[n];

    less[0] = arr[0];
    more[n-1] = arr[n-1];

    int temp = -1;

    for(int i = 1;i<n;i++){
        less[i] = min(arr[i],less[i-1]);
    }

    for(int i = n-2;i>=0;i--){
        more[i] = max(arr[i],more[i+1]);
    }

    int x = 0;
    int y = 0;

    while(x < n && y< n){

        // less[x] and more[y] roughly correspond to A[i] and A[j]
        if(less[x] <= more[y]){
            temp = max(temp,y-x);
            y++;
        }
        else{
            x++;
        }
    }

    return temp;

}
