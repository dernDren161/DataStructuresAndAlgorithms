// Problem Link: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/3025/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.empty())
            return "";
        unordered_map<char,unordered_set<char>>graph;
        unordered_map<char,int>inDegree;

        //intializing indegrees to 0
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                inDegree[words[i][j]]=0;
            }
        }
        //i think this is the hardest part to grasp, read the solution to understand the logic on why we use this logic and then come back here
		//after this, its simply a bfs using indegrees
        for(int i=0;i<words.size()-1;i++)
        {
            string cur=words[i];
            string next=words[i+1];
            int lenght=min(cur.size(),next.size());
            for(int j=0;j<lenght;j++ )
            {
                if(cur[j]!=next[j])
                {
                    if(graph[cur[j]].find(next[j])==graph[cur[j]].end())
                    {
                        graph[cur[j]].emplace(next[j]);
                        inDegree[next[j]]++;
                    }
                     break;
                }
                if(j==lenght-1 and cur.size()>next.size())
                    return "";
            }

        }
        string res;
        queue<char>bfs;

        for(auto &it:inDegree)//push only when degree is set to 0
        {
            if(it.second==0)
            {
                bfs.push(it.first);
            }
        }
        while(!bfs.empty()) //simply a bfs using indegrees (top sort)
        {
            auto c=bfs.front();
            bfs.pop();
            res+=c;
            for(auto &neighbor:graph[c])
            {
                inDegree[neighbor]--;
                if(!inDegree[neighbor])
                {
                    bfs.push(neighbor);
                }
            }
        }
        return res.size()==inDegree.size()?res:"";// in case there is a cycle, will return empty string
    }
};
