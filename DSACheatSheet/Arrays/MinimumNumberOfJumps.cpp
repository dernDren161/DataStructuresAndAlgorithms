// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int previous = 0;
        int jump = 0;
        int current = 0;

        if(arr[0]==0) return -1;

        for(int i=0;i<n;i++){
            if(i>previous){
                if(i>current) return -1;
                jump++;
                previous = current;
            }
            current = max(current,i+arr[i]);
        }
        return jump;
    }
};
