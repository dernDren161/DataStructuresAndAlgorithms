// Problem Link: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/0/?track=GTS-ARRAY&batchId=397

class Solution{
  public:

    int majorityElement(int a[], int size)
    {

        int n = size;
        int maxi = 0;
        int c = 1;

        for(int i=1;i<n;i++){
            if(a[maxi]==a[i]){
                c++;
            }else c--;

            if(c==0){
                maxi = i;
                c = 1;
            }
        }

        // probable answer is a[maxi]
        int g = 0;
        for(int i=0;i<n;i++){
            if(a[i]==a[maxi])g++;
        }

        return (g>n/2)?a[maxi]:-1;

    }
};
