// Problem Link: https://leetcode.com/explore/interview/card/facebook/53/recursion-3/267

class Solution {
public:

    vector<string> res;

// NOTE: here elements are not passed by reference, so as to maintain the values of 'x' and 'prefix' in each
// individual recursive calls in the function

    void call(vector<string> c, string digits, int x, string prefix){

        if(x >= digits.length()){
            res.push_back(prefix);
            return;
        }
        string temp = c[digits[x]-'0'];

        for(int i=0;i<temp.size();i++){
            call(c,digits,x+1,prefix + temp[i]);
        }

    }
    vector<string> letterCombinations(string digits) {

        if(digits.length() <= 0) return {};

        vector<string> collect = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        string empt ="";
        call(collect,digits,0,empt);

        return res;
    }
};
