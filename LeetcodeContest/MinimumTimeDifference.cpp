// Problem Link: https://leetcode.com/problems/minimum-time-difference/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        int n = timePoints.size();

        // converting to minute integers
        vector<int>mins;

        for(string s:timePoints){
            string firstHalf = s.substr(0,2);
            string secondHalf = s.substr(3,2);

            int temp = ((firstHalf[0]-'0')*60*10 + ((firstHalf[1]-'0')*60)) + ((secondHalf[0]-'0')*10) + (secondHalf[1]-'0');
            mins.push_back(temp);
        }

        sort(mins.begin(),mins.end());
        int ans = INT_MAX;

        for(int i=1;i<n;i++){
            ans = min(ans,mins[i]-mins[i-1]);
        }

        return min(ans,(1440-mins[n-1])+mins[0]);
    }
};
