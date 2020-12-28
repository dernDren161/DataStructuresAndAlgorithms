// Problem Link: https://leetcode.com/explore/interview/card/facebook/54/sorting-and-searching-3/310/

class Solution {

    static bool comp(vector<int> &a, vector<int>& b){
        return a[0]<b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*
        Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
        Output: [[1,6],[8,10],[15,18]]
        */

        if(intervals.size() == 0) return {};

        sort(intervals.begin(),intervals.end(),comp);

        int l = intervals[0][0];
        int r = intervals[0][1];

        vector<vector<int>> ans;

        for(int i=1;i<intervals.size();i++){

            if(intervals[i][0]<=r){ // can be merged
                r = max(r,intervals[i][1]);
            }else{ // can't be merged
                ans.push_back({l,r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }

        ans.push_back({l,r});

        return ans;
    }
};
