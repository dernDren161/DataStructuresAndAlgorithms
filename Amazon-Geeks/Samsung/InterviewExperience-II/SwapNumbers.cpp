// Problem Link: https://practice.geeksforgeeks.org/problems/swap-two-numbers3844/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung

class Solution{
public:
    pair<int, int> get(int a, int b){
        //complete the function here
        a = a + b;
        b = a - b;
        a = a - b;

        pair<int,int> ans;

        ans = {a,b};

        return ans;
    }
};
