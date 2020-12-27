// Problem Link: https://leetcode.com/explore/interview/card/facebook/53/recursion-3/324/
// My Own trick: in this recursion it is more like an inorder traversal
// It goes to the extreme point and then start pushing into the vector

class Solution {
public:

    //         getValid(s , valid, invalid, 0 , h , "" , 0);
    void getValid(string& s, unordered_set<string>& valid, int& invalid , int l , int& h, string temp, int sum)
    {

        if(sum < 0 ) return;
        if(l == h && s.size() - temp.size() == invalid && sum == 0)
        {
            valid.insert(temp);
            return;
        }

        if(l==h) return; // means reached 'h' but hence formed 'temp' is not yet valid, so just return to the callee.

        if(s[l] == '(' || s[l] == ')')
        {
             getValid(s , valid, invalid, l+1, h , temp, sum); // s[l] not included
        }

        temp = temp + s[l]; // s[l] included

        if(s[l] == '(')
        {
            sum += 1;
        }
        else if(s[l] == ')')
        {
            sum -= 1;
        }

        getValid(s , valid, invalid, l+1, h , temp, sum);

    }


    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> valid;
        int invalid = 0 ; // # of invalid parenthesis
        int sum = 0;

        while(s[0] == ')')
        {
            s.erase(0,1);
        }

        while(s[s.size()-1] == '(')
        {
            s.erase(s.size()-1,1);
        }

        for(int i  = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '(')
            {
                sum++;
            }
            else if(s[i] == ')')
            {
                sum--;
            }

            if(sum < 0)
            {
                invalid++;
                sum = 0;
            }
        }

        invalid += sum;
        int h = s.size();
        getValid(s , valid, invalid, 0 , h , "" , 0);
        if(valid.size() == 0 ) return {""};
        vector<string> v(valid.begin() , valid.end());

        return v;

    }
};
