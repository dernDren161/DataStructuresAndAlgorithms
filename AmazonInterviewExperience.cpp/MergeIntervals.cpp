// Problem Link: https://leetcode.com/explore/interview/card/facebook/54/sorting-and-searching-3/310/
// NOTE: In Meeting Rooms you sort w.r.t the ending time
// NOTE: In this question you sort w.r.t the starting time

class Solution {
public:

    static bool comp(vector<int>&a, vector<int>&b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*
        INPUT:
                1,3
                2,6
                8,10
                15,18
        */

        // sort w.r.t the starting time

        if(intervals.size()==0) return {};

        sort(intervals.begin(),intervals.end(),comp);

        int start;
        int end;

        start = intervals[0][0];
        end = intervals[0][1];

        vector<vector<int>> result;

        for(int i=1;i<intervals.size();i++){
            if(end>=intervals[i][0]){
                end = max(end,intervals[i][1]);
            }else{
                result.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        result.push_back({start,end});

        return result;
    }
};
