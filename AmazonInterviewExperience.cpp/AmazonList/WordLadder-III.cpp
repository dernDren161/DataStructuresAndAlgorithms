// Problem Link: https://leetcode.com/problems/minimum-genetic-mutation/
// NOTE: Asked in twitter

class Solution {
public:

    char alpha[4] = {'A','C','G','T'};

    int minMutation(string start, string end, vector<string>& bank) {

        unordered_set<string>dict(bank.begin(),bank.end());
        unordered_map<string,bool>check;
        queue<pair<string,int>>qs;
        qs.push({start,0});

        while(!qs.empty()){
            auto x = qs.front();
            qs.pop();
            string s = x.first;
            int dist = x.second;
            string temp = s;

            if(s==end) return dist;

            for(int i=0;i<s.size();i++){
                for(int j=0;j<4;j++){
                    if(temp[i]==alpha[j])continue;
                    temp[i] = alpha[j];

                    if(dict.find(temp)!=dict.end()&& !check[temp]){
                        check[temp] = true;
                        qs.push({temp,dist+1});
                    }
                }
                temp[i] = s[i];
            }
        }

        return -1;
    }
};
