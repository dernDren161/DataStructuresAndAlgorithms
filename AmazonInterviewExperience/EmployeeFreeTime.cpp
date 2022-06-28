// Problem Link: https://leetcode.com/problems/employee-free-time/
// The code does not run but the concept is correct
// NOTE: Do "MergeIntervals","NMeetingRooms" and this question together as they are similar

class Solution {
public:

    static bool comp(Interval a, Interval b){
        return a.start < b.start;
    }

    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {

       // if(schedule.size()==0) return {};

        vector<Interval> vs;

        for(int i=0;i<schedule.size();i++){
            for(int j=0;j<schedule[0].size();j++){
                vs.push_back(schedule[i][j]);
            }
        }

        // sorting in ascending order
        sort(vs.begin(),vs.end(),comp);

        int ending = vs[0].end;

        vector<Interval> result;

        for(int i=1;i<vs.size();i++){
            if(ending < vs[i].start){
                result.push_back(Interval(ending,vs[i].start));
            }
            ending = max(ending,vs[i].end);
        }

        return result;
    }
};
