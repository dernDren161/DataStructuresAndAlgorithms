// Problem Link: https://practice.geeksforgeeks.org/problems/multiply-two-polynomals0721/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung

class Solution{
    public:
    vector<int>polyMultiply(int Arr1[], int Arr2[], int M, int N)
    {
        // code here
        vector<int> ans(M+N-1);

        // NOTE: never use 'memset' with things like vector and strings, containers in general
        fill(ans.begin(),ans.end(),0);

        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                ans[i+j] += (Arr1[i] * Arr2[j]);
            }
        }

        return ans;
    }
};
