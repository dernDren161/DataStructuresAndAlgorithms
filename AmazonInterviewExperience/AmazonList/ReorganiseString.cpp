// Problem Link: https://leetcode.com/problems/reorganize-string/
// T.C: O(n log k)
// S.C: O(k)

class Solution {
public:
    string reorganizeString(string s) {

        if(s.size()==0) return "";

        unordered_map<char,int>m; // key-character and value-frequency
        priority_queue<pair<int,char>>pq;

        int n = (s.length()+1)/2;

        for(char c:s){
            m[c]++;

            if(m[c]>n) return "";
        }

        for(auto it:m){
            pq.push({it.second,it.first});
        }

        string res = "";

        while(!pq.empty()){
            auto temp1 = pq.top();
            pq.pop(); // temporarily deleting the first character

            res += temp1.second;
            temp1.first--;

            if(!pq.empty()){
                auto temp2 = pq.top();
                pq.pop();

                res += temp2.second;
                temp2.first--;
                if(temp2.first>0)pq.push(temp2);
            }

            if(temp1.first>0)pq.push(temp1);

        }

        return res;
    }
};
