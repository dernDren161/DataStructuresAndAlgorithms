// Problem Link: https://leetcode.com/problems/kill-process/

class Solution {
private:
    vector<int>res;
    unordered_map<int, vector<int> > adjList; // NOTE: IMP 

public:
    void dfs(int id )
    {
        res.push_back(id);

        for(auto& child: adjList[id])
        {
            dfs(child);
        }

    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill)
    {
        for(int i = 0; i < pid.size(); i++)
        {
            adjList[ppid[i]].push_back(pid[i]);
        }
        dfs(kill);
        return res;
    }
};
