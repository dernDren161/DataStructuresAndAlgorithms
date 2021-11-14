// Problem Link: https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung#

class Solution{
public:
    int minimumStep(int n){
        //complete the function here

       int c = 0;

       while(n>1){ // NOTE: n>1 is an important part as to reach 1 we need 0 steps
           if(n%3==0){
               c++;
               n = n/3;
           }else{
               c++;
               n--;
           }
       }

       return c;
    }
};
