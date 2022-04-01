// Problem Link: https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(newInterval[0] > intervals[i][1]){
                ans.push_back(intervals[i]);
            }else if(newInterval[1] < intervals[i][0]){
                ans.push_back(newInterval);
                for(int k=i;k<n;k++){
                    ans.push_back(intervals[k]);
                }
                return ans;
            }else{ // when I push the 'newInterval' at the very first
                int start = min(intervals[i][0],newInterval[0]);
                int end = max(intervals[i][1],newInterval[1]);
                newInterval[0] = start;
                newInterval[1] = end;
            }
        }

        ans.push_back(newInterval);
        return ans;
    }
};
