// Problem Link: https://leetcode.com/problems/valid-parentheses/submissions/

class Solution {
public:
    bool isValid(string s) {

        int n = s.length();
        if(n==0) return true;

        stack<char> st;

        for(int i=0;i<n;i++){

            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else if(s[i]==')' && (!st.empty()) && st.top()=='(') st.pop();
            else if(s[i]=='}' && (!st.empty()) && st.top()=='{') st.pop();
            else if(s[i]==']' && (!st.empty()) && st.top()=='[') st.pop();
            else return false;
        }

        // NOTE: important note, do this.
        if(st.empty()) return true;

        return false;
    }
};
