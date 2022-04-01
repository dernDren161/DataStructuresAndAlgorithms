// Problem Link: https://leetcode.com/explore/interview/card/google/59/array-and-strings/3059/
/*
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        int n = intervals.size();

        map<int,int>m;

        for(int i=0;i<n;i++){
            m[intervals[i][0]]++;
            m[intervals[i][1]]--;
        }

        int res = 0;
        int maxi = 0;

        for(auto it:m){
            maxi = max(maxi, res += (it.second));
        }

        return maxi;
    }
};
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        int n = intervals.size();
        int start[n];
        int end[n];

        for(int i=0;i<n;i++){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        sort(start,start+n);
        sort(end,end+n);

        int i=1; int j = 0;
        int rooms = 1;

        int ans = 1;

        while(i<n && j<n){
            if(start[i]< end[j]){
                rooms++;
                i++;
            }else if(start[i]>=end[j]){
                rooms--;
                j++;
            }
            ans = max(ans,rooms);
        }

        return ans;
    }
};
