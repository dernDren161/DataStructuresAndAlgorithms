// Problem Link: https://leetcode.com/problems/minimum-number-of-refueling-stops/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        int cnt = 0;
        int n = stations.size();
        priority_queue<int>pq;
        int i = 0;

        while(i<n && startFuel<target){
            int temp = i;
            while(i<n && startFuel>=stations[i][0]){
                pq.push(stations[i++][1]);
            }

            while(!pq.empty() && ((i<n && startFuel<stations[i][0]) || (i==n && startFuel<target))){
                startFuel += pq.top();
                pq.pop();
                cnt++;
            }

            if(i==temp) return -1;
        }

        if(target>startFuel) return -1;

        return cnt;
    }
};
