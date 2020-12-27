// Problem Link: https://leetcode.com/explore/interview/card/facebook/53/recursion-3/267

class Solution {
    vector<string> res;
    vector<string> collect = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


    void call(string digits){

        queue<string> qs;
        qs.push("");

        while(!qs.empty()){
            string f = qs.front();
            qs.pop();

            if(f.length() == digits.length()){
                res.push_back(f);
            }else{
                for(char c : collect[digits[f.size()]-'0']){
                    qs.push(f+c);
                }
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {

        if(digits.size() <= 0) return {};


        call(digits);

        return res;
    }
};
