// Problem Link: https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {

        int n = s.size();
        stack<int>st;
        st.push(-1);
        int ans = 0;

        for(int i=0;i<n;i++){
            if(st.top()!=-1 && s[i]==')' && s[st.top()]=='('){
                st.pop();
                ans = max(ans,i-st.top());
            }else{
                st.push(i);
            }
        }

        return ans;
    }
};
