// Problem Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// NOTE: Maybe similar algorithm was used to create the game "Candy Crush" :)

class Solution {
public:
    string removeDuplicates(string s, int k) {

        stack<pair<char,int>> st;

        for(int i=0;i<s.size();i++){
            if(st.empty() || st.top().first!=s[i]){
                st.push({s[i],1}); // NOTE: Important step
            }else{
                st.top().second++;
            }

            if(st.top().second==k)st.pop();
        }

        string res;
        int times;

        while(!st.empty()){
            res.append(st.top().second,st.top().first); // append(no. of times, character to be repeated)
            st.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};
