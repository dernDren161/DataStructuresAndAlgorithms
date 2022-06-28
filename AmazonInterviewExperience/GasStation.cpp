// Problem Link: https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int start = 0; // starting index
        int cur = 0;
        int total = 0;

        for(int i=0;i<cost.size();i++){

            total += (gas[i]-cost[i]);
            cur += (gas[i]-cost[i]);

            if(cur<0){
                start = i+1;
                cur = 0;
            }
        }

        return (total>=0 ? start:-1);
    }
};
