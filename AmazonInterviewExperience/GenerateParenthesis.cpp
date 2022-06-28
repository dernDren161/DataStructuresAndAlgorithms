// Problem Link: https://leetcode.com/problems/generate-parentheses/
// T.C: each result(valid or invalid) generates 2n length string and since a recursive tree is formed so, O(2^2n)
// S.C: Same as the T.C

class Solution {

    public:
    vector<string> ans;

    void callToGenerate(string temp, int open, int close){

        if(open==0 && close==0){
            ans.push_back(temp);
            return;
        }

        if(open>0){
            temp.push_back('(');
            callToGenerate(temp,open-1,close);
            temp.pop_back();
        }

        if(close>0 && open<close){
            temp.push_back(')');
            callToGenerate(temp,open,close-1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        string temp = "";

        callToGenerate(temp,n,n);

        return ans;
    }
};
