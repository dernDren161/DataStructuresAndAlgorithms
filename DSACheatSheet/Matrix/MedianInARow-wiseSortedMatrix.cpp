// Problem Link: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#

class Solution{
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here
          int min=INT_MAX,max=INT_MIN;
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]<min)
            {
                min=matrix[i][0];
            }

            if(matrix[i][matrix[i].size()-1]>max)
            {
                max=matrix[i][matrix[i].size()-1];
            }
        }
        int desired=(r*c+1)/2;
        while(max>min) // NOTE:: Exception here I use as I want to return max/min i.e the middle element after the while loop.
        {
            int mid=min + (max-min)/2;
            int place=0;

            for(int i=0;i<matrix.size();i++)
            {
                place+=upper_bound(matrix[i].begin(),matrix[i].end(),mid) -matrix[i].begin();
            }
            if(place<desired)
            {
                min=mid+1;
            }
            else
            {
                max=mid;
            }
        }
        return min;// NOTE: You can even return 'max' also as both 'min' and 'max' come to middle which is the answer.
    }
};
