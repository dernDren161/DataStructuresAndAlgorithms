// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/288/

class Solution {
public:
    bool isPalindrome(string s) {
        /*
        Input: "A man, a plan, a canal: Panama"
        Output: true
        */

        int n = s.length();

        int l = 0;
        int r = n-1;

        while(l<=r){

            //NOTE: to check if the character does not fall into alphanumeric, you have to write
            
            // if(!isalpha(s[i]) && !isdigit[s[i]])) ----->> is not alphanumeric, the correct way

            // if(!((isalpha(s[i]) && isdigit(s[i]))) --->> wrong way, as it is logically incorrect for AND

            if((!isalpha(s[l]) && !isdigit(s[l]))) l++;
            else if((!isalpha(s[r]) && !isdigit(s[r]))) r--;
            else if(tolower(s[l])==tolower(s[r])){
                l++;
                r--;
                continue;
            }else{
                return false;
            }
        }

        return true;
    }
};
