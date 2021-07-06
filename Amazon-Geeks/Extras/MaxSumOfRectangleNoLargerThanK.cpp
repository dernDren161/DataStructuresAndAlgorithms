// Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3801/

class Solution {
public:

    // Normal Kadane's variation routine
    int callKadane(vector<int> &vs, int n, int k){

        int m = INT_MIN;
        int sum = 0;

        set<int> s;
        s.insert(0);

        for(int i=0;i<n;i++){

            sum += vs[i];

            auto p = s.lower_bound(sum-k);

            if(p != s.end()){ // if found
                m = max(m,sum-*p);
            }

            s.insert(sum);
        }

        return m;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int row = matrix.size();
        int col = matrix[0].size();

        int ans = -1;

        for(int i=0;i<row;i++){
            vector<int> vs(col,0);

            for(int j=i;j<row;j++){
                for(int x=0;x<col;x++){
                    vs[x] += matrix[j][x];
                }

                ans = max(ans,callKadane(vs,col,k));
            }
        }

        return ans;
    }
};
