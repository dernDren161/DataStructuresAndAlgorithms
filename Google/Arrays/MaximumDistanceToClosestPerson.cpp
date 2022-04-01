// Problem Link: https://leetcode.com/problems/maximize-distance-to-closest-person/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        int n = seats.size();
        int ans = INT_MIN;
        int prev = -1;

        for(int i=0;i<n;i++){
            if(seats[i]==1){
                if(prev==-1){
                    ans = i;
                }else{
                    ans = max(ans,(i-prev)/2);
                }
                prev = i;
            }
        }

        ans = max(ans,(n-1)-prev);
        return ans;
    }
};
