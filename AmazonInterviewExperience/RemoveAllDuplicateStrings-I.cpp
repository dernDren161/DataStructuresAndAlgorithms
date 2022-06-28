// Problem Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Algo maybe used for Candy Crush

class Solution {
public:
    string removeDuplicates(string s) {

        int n = s.size();

        stack<pair<char,int>> st;

        for(int i=0;i<n;i++){
            if(st.empty() || st.top().first!=s[i]){
                st.push({s[i],1});
            }else{
                st.top().second++;
            }

            if(st.top().second>1)st.pop();
        }

        string res = "";

        while(!st.empty()){

            res.append(st.top().second,st.top().first);
            st.pop();
        }

         reverse(res.begin(),res.end());

        return res;
    }
};
