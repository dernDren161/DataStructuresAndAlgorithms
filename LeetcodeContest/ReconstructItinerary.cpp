// Problem Link: https://leetcode.com/problems/reconstruct-itinerary/
// NOTE: This solution just finds the Eulerian path in the graph and the algorithm is called as "Hierholzer Algorithm"

class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>graph;
    stack<string>ans;

    void callDFS(string s){

        auto& qs = graph[s];

        while(!qs.empty()){
            string f = qs.top();
            qs.pop();
            callDFS(f);
        }

        ans.push(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto x:tickets){
            graph[x[0]].push(x[1]);
        }

        callDFS("JFK");

        vector<string>res;
        while(!ans.empty()){
            res.push_back(ans.top());
            ans.pop();
        }

        return res;
    }
};
