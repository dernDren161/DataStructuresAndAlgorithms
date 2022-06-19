// Problem Link: https://leetcode.com/contest/weekly-contest-290/problems/count-number-of-rectangles-containing-each-point/

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {

        int n = points.size();
        map<int,vector<int>>myMap; // y ,{x};
        sort(rectangles.begin(),rectangles.end());

        for(vector<int>x:rectangles){
            myMap[x[1]].push_back(x[0]);
        }

        vector<int>res;

        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];

            auto it = myMap.lower_bound(y);
            int ans = 0;

            while(it!=myMap.end()){
                auto itt = lower_bound(it->second.begin(),it->second.end(),x);


                    ans += (it->second.end()-itt);

                it++;
            }

            res.push_back(ans);
        }

        return res;
    }
};
