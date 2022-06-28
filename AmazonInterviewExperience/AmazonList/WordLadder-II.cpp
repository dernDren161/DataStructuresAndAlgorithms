// Problem Link: https://leetcode.com/problems/word-ladder-ii/
/*
Time complexity: O(NK^2 + α)

Here NN is the number of words in wordList, KK is the maximum length of a word, αα is the number of possible paths from beginWord to endWord in the directed graph we have.

Space complexity: {O}(NK)O(NK)
*/

class Solution {
public:
    vector<vector<string>> ans;
    void dfs(string b, string e, unordered_map<string, unordered_set<string>> adj, vector<string> p) {
        p.push_back(b);
        if(b == e) {
            ans.push_back(p);
            p.pop_back();
        }

        for(auto x: adj[b]) {
            dfs(x, e, adj, p);
        }

        p.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string, unordered_set<string>> adj;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> vis;

        vis[beginWord] = 0;
        queue<string> q;
        q.push(beginWord);

        while(!q.empty()) {
            string cur = q.front();     q.pop();
            string tmp = cur;

            for(int i = 0; i < cur.size(); i++) {
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    if(tmp[i] == ch)
                        continue;

                    tmp[i] = ch;
                    if(dict.find(tmp) != dict.end()) {
                        if(vis.find(tmp) == vis.end()) {
                            vis[tmp] = vis[cur] + 1;
                            q.push(tmp);
                            adj[cur].insert(tmp);
                        } else if(vis[tmp] == vis[cur] + 1) {/*
                              The use of this line is to check if the node tmp is already visited, since
                              it is a BFS solution vis[tmp]==vis[cur]+1 is satisfied only in the very first encounter
                              and if that same element is found later on then the above condition does not hold true,
                              also it pushes the node taking the least steps hence justifying the use of BFS to find the
                              shortest path.
                          */
                            adj[cur].insert(tmp);
                        }
                    }
                }

                tmp[i] = cur[i];
            }
        }

        vector<string> path;
        dfs(beginWord, endWord, adj, path);

        return ans;

    }
};
