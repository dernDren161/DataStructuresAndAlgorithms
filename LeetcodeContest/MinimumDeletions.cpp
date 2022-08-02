// Problem Link: https://leetcode.com/contest/weekly-contest-302/problems/minimum-deletions-to-make-array-divisible/

class Solution {
public:

    // T.C is log(min(a,b))
    int findGCD(int a, int b){

        if(a==0) return b;

        return findGCD(b%a,a);
    }

    int minOperations(vector<int>& nums, vector<int>& numsDivide) {

        // find the GCD of numsDivide
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int gcd = numsDivide[0];

        for(int i=1;i<numsDivide.size();i++){
            gcd = findGCD(gcd,numsDivide[i]);
        }

        int x = 0;

        for(int i=0;i<n;i++){
            if(gcd%nums[i] == 0){
                break;
            }
            x++;
        }

        if(x==n) return -1;

        return x;
    }
};
