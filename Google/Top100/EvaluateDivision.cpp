//Problem Link: https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    void callDFS(string a, string b, double tempAns, map<string,map<string,double>>&myMap, set<string>&vis, double& finalRes){

        vis.insert(a);

        if(a==b){
            finalRes = tempAns;
        }
        for(auto x:myMap[a]){
            if(vis.find(x.first)==vis.end()){
                vis.insert(x.first);
                tempAns *= x.second;
                callDFS(x.first,b,tempAns,myMap,vis,finalRes);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        map<string,map<string,double>>myMap;
        set<string>mySet;

        for(int i=0;i<equations.size();i++){
            myMap[equations[i][0]][equations[i][1]] = values[i];
            myMap[equations[i][1]][equations[i][0]] = 1.0/values[i];
            mySet.insert(equations[i][0]);
            mySet.insert(equations[i][1]);
        }

        vector<double> ans;

        for(int i=0;i<queries.size();i++){
            if(mySet.find(queries[i][0])==mySet.end() || mySet.find(queries[i][1])==mySet.end()){
                ans.push_back(-1.00000);
                continue;
            }else{
                double tempAns = 1.0;
                set<string>vis;
                double finalRes=-1.0;
                callDFS(queries[i][0],queries[i][1],tempAns,myMap,vis,finalRes);
                ans.push_back(finalRes);
            }
        }

        return ans;
    }
};
