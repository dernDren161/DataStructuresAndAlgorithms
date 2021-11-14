// Problem Link: https://leetcode.com/problems/word-ladder/

cclass Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {


        unordered_map<string,bool> check;

        for(string s:wordList) check[s] = false;

        unordered_set<string> words(wordList.begin(),wordList.end());

        queue<pair<string,int>> qs;
        qs.push({beginWord,1});

        while(!qs.empty()){

            string cur = qs.front().first;
            int dist = qs.front().second;
            qs.pop();
            string temp = cur;

            if(cur==endWord){
                return dist;
            }

                for(int i=0;i<cur.size();i++){
                    for(char x='a';x<='z';x++){
                        if(temp[i]==x) continue;

                        temp[i] = x;

                        if(words.find(temp)!=words.end() && !check[temp]){
                            check[temp] = true;
                            qs.push({temp,dist+1});
                        }
                    }
                    temp[i] = cur[i];
                }
        }

        return 0;
    }
};
