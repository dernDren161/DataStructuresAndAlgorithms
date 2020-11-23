// Problem Link:
//https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1


class Solution{

public:
    int call(int arr[], int l, int r, int x){
            // left
            int res = -1;
            while(l<=r){
                int m = l + (r-l)/2;

                if(arr[m] == x){
                    res = m;
                    r = m-1;
                }else if(arr[m] > x){
                   // res = m;
                    r = m-1;
                }else{
                    l = m+1;
                }
            }

            return res;
    }

    public:
    int call2(int arr[], int l, int r, int x){
            // right
            int res = -1;
            while(l<=r){
                int m = l + (r-l)/2;

                if(arr[m] == x){
                    res = m;
                    l = m+1;
                }else if(arr[m] > x){
                    //res = m;
                    r = m-1;
                }else{
                    l = m+1;
                }
            }

            return res;
    }

public:
	int count(int arr[], int n, int x) {

	    int firstIndex = call(arr,0,n-1,x);
	    int lastIndex = call2(arr,0,n-1,x);

	    if(firstIndex== -1 && lastIndex == -1) return 0;

	    return (lastIndex - firstIndex) + 1;
	}
};
