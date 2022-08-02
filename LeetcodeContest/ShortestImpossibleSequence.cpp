// Problem Link: https://leetcode.com/contest/biweekly-contest-83/problems/shortest-impossible-sequence-of-rolls/

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {

        int n = rolls.size();
        int ans = 1;

        set<int>s;

        for(int i=0;i<n;i++){
            s.insert(rolls[i]);

            if(s.size()==k){
                ans++;
                s.clear();
            }
        }

        return ans;
    }
};
