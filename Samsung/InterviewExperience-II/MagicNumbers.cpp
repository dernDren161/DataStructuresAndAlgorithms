// Problem Link: https://practice.geeksforgeeks.org/problems/faithful-numbers0014/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung#
// Also called "Faithful Numbers"
// IMP: to divide by 2 we do: N>>=1;

class Solution {
  public:
    long long nthFaithfulNum(int N) {

        long long int x = 0;
        long long int c = 0;

        while(N){

            if(N&1){
                x += (1 * (pow(7,c)));
            }else{
                x += (0 * (pow(7,c)));
            }

            N>>=1; // IMP: same as N /= 2;
            c++;
        }

        return x;
    }
};
