class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        unordered_map<string,int>indeg;
        unordered_map<string,vector<string>>adj;

        for(vector<string>x:ingredients){
            for(string y:x){
                indeg[y] = 0;
            }
        }
        // construct the adjacency list

        for(int i=0;i<ingredients.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                adj[ingredients[i][j]].push_back(recipes[i]);
                indeg[recipes[i]]++;
            }
        }

        set<string>mySet(supplies.begin(),supplies.end());

        queue<string>qs;

       for(string s:mySet){
           auto it = indeg.find(s);
           if(it!=indeg.end()){
               if(it->second == 0){
                   qs.push(s);
               }
           }
       }

        vector<string>ans;

        while(!qs.empty()){
            string f = qs.front();
            qs.pop();

            for(string x:adj[f]){
                indeg[x]--;
                if(indeg[x]==0){
                    qs.push(x);
                    ans.push_back(x);
                }
            }
            adj.erase(f);
        }

        return ans;
    }
};
