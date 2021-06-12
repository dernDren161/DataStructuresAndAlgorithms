// Problem Link: https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {


         /*   hit--->hot--->dot--->dog--->cog
                    |
                    lot
                    |
                    log
                    |
                    cog*/

        //Convert into a set, for constant lookup

        if(beginWord.empty() || endWord.empty() || wordList.empty())return 0;

        unordered_set<string> wordSet;

        for(auto w : wordList)
        {
            wordSet.insert(w);
        }

        //return the length of the shortest transformation

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                string currWord = q.front().first;
                int level = q.front().second;
                q.pop();
               if(!currWord.compare(endWord))return level + 1;

               unordered_set<string>::iterator itr = wordSet.begin();
               while(itr != wordSet.end())
               {
                    if(isAdjacentWord(currWord, *itr))
                    {
                       if(*itr == endWord)return level+1;
                       q.push({*itr, level + 1});
                       itr = wordSet.erase(itr);
                    }
                    else
                    {
                         itr++;
                    }

               }

            }
        }
         return 0;

        }

    private:
    bool isAdjacentWord(string w1, string w2)
    {
        int cnt = 0;
        for(int i =0; i < w1.length(); i++)
        {
            if(w1[i] != w2[i])cnt++;
            if(cnt > 1)return false;
        }
        return cnt == 1 ? true : false;
    }
};
