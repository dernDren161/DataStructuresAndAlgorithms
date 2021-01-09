// Problem Link: https://leetcode.com/problems/meeting-rooms/

class Solution {

    static bool comp(pair<int,int> a, pair<int,int>b){
        return a.second < b.second;
    }

public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {

        if(intervals.size() == 0) return true;
        if(intervals.size() == 1) return true;

        vector<pair<int,int>> vs;

        for(int i=0;i<intervals.size();i++){
            vs.push_back(make_pair(intervals[i][0],intervals[i][1]));
        }

        // with sort and 'comp', always use the static access modifier for 'comp'.
        sort(vs.begin(),vs.end(),comp);

        for(int i=0;i<vs.size()-1;i++){
            if(vs[i].second <= vs[i+1].first) continue;
            else return false;
        }

        return true;
    }
};
