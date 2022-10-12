// Problem Link: https://practice.geeksforgeeks.org/problems/set-bits0143/1/?company[]=Samsung&company[]=Samsung&page=1&query=company[]Samsungpage1company[]Samsung#

class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int c = 0;

        while(N){
            N = N & (N-1);
            c++;
        }

        return c;
    }
};
