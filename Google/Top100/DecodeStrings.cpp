// Problem Link: https://leetcode.com/problems/decode-string/

// T.C: O((m^k)*n)
// m-- is the maximum number outside the bracket, k-- is the occurences of number digits and
// n-- lenghth of the longest string 

class Solution {
public:
    string decodeString(string s) {

        int n = s.size();
        stack<char>st;

        for(int i=0;i<n;i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }else{
                string res = "";
                while(st.top()!='['){
                    res += st.top();
                    st.pop();
                }

                st.pop();
                int k = 0;
                int base = 1;
                while(!st.empty() && isdigit(st.top())){
                    k = k + (base * (st.top()-'0'));
                    st.pop();
                    base*=10;
                }

                while(k--){
                    for(int i=res.size()-1;i>=0;i--){
                        st.push(res[i]);
                    }
                }
            }
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top(); st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
