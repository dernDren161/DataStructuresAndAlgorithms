// Problem Link: https://practice.geeksforgeeks.org/problems/three-way-partitioning/1#

// The code does not run but the logic is correct
// Same as the Dutch flag algorithm

void swap(int arr[],int a, int b){
    int three;
    three = arr[a];
    arr[a] = arr[b];
    arr[b] = three;
}
void threeWayPartition(int arr[], int n, int a, int b)
{
    int low = 0;
    int high = n-1;

    for(int i=0;i<=high;i++){
        if(arr[i]<a){
            swap(arr,low,i);low++;i++;
        }else if(arr[i]>b){
            swap(arr,i,high);high--;
        }else i++;  // NOTE: This else considers any case where, a[i]>a[low] || a[i]<a[high]
    }
}
