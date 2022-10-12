// Problem Link: https://practice.geeksforgeeks.org/problems/change-all-even-bits-in-a-number-to-03253/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung

class Solution {
  public:
    long long int convertEvenBitToZero(long long int n) {

        long long int m = 0;
        long long int sub = 0;

        for(long long int i=n;i;i>>=2){
            if(i & 1){
                sub += (1<<m); // = m * (2 ^ 1)
            }
            m +=2;
        }

        return n - sub;
    }
};
