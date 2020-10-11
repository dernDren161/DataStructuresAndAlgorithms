// Problem Link: https://practice.geeksforgeeks.org/problems/check-set-bits5408/1/?company[]=Amazon&problemStatus=unsolved&page=1&query=company[]AmazonproblemStatusunsolvedpage1

class Solution{
public:
    int isBitSet(int N){

        int c1 = 0;
        int temp = N;
        while(N){
            N = N/2;
            c1++;
        }

        int c2 = 0;
        while(temp){
            temp = temp & (temp-1);
            c2++;

        }

        if(c1 == c2) return 1;
        return 0;
    }
};
