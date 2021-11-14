/*
// Problem Link: https://practice.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung#

Here, 0x0F is --  0000 1111
      0xF0 is --  1111 0000
*/

class Solution{
public:
    int swapNibbles(unsigned char x){

        return ((x & 0x0F)<<4 | (x & 0xF0)>>4);
    }
};
