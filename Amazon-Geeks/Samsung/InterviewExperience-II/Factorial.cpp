// Problem Link: https://practice.geeksforgeeks.org/problems/factorial5739/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung#

long long int factorial(int N){
       //code here

       if(N==0 || N==1) return 1;

       return N * factorial(N-1);
}
