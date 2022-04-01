// Problem Link: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    int callDist(int x, int y){
        return x*x + y*y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {


        int n = points.size();

        // Finding the k smallest number pairs w.r.t the distance

        priority_queue<pair<int,int>> pq; // distance and row

        for(int i=0;i<k;i++){
            int dist = callDist(points[i][0],points[i][1]);
            pq.push(make_pair(dist,i));
        }

        for(int i=k;i<n;i++){
            int tempDist = callDist(points[i][0],points[i][1]);
            if(pq.top().first > tempDist){
                pq.pop();
                pq.push(make_pair(tempDist,i));
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()){
            auto f = pq.top();
            int index = f.second;
            ans.push_back({points[index][0],points[index][1]});
            pq.pop();
        }

        return ans;
    }
};
