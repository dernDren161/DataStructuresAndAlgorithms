// Problem Link: https://leetcode.com/contest/biweekly-contest-72/problems/maximum-split-of-positive-even-integers/

class Solution {
public:

    bool callBackTrack(long long finalSum, long long sum, long long x, vector<long long>&ans){

        if(sum==0) return true;
        if(sum<0 || x>sum) return false;

        for(int i=x;i<=finalSum;i+=2){
            ans.push_back(i);
            if(callBackTrack(finalSum,sum-i,i+2,ans))return true; // This is the optimisation here.
            ans.pop_back();
        }

        return false;
    }

    vector<long long> maximumEvenSplit(long long finalSum) {

        if(finalSum%2 != 0) return {};

        vector<long long> ans;

        if(finalSum==2){
            ans.push_back(finalSum);
            return ans;
        }
        ans.clear();
        bool i = callBackTrack(finalSum,finalSum,2,ans);

        return ans;
    }
};
