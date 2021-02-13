// Problem Link:
//https://practice.geeksforgeeks.org/problems/find-the-highest-number2259/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1

// This problem is to be done in: O(logn) time

class Solution {

    int call(vector<int>& a, int l, int r){

        while(l<=r){

            int m = l + (r-l)/2;

            if((a[m]>a[m-1])&&(a[m]>a[m+1])) return a[m];

            else if((a[m]<a[m-1]) && (a[m]>a[m+1])) r = m-1;

            else if((a[m]>a[m-1])&&(a[m]<a[m+1])) l = m+1;
        }


    }
public:
    int findPeakElement(vector<int>& a)
    {
        int s = a.size();

        return call(a,0,s-1);
    }

};
