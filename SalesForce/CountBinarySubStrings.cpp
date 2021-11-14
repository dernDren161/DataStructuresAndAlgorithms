// Problem Link: https://leetcode.com/problems/count-binary-substrings/

class Solution {
public:
    int countBinarySubstrings(string s) {

        int current = 1;
        int previous = 0;

        int ans = 0;

        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                current++;
            }else{ // i count during the transitions
                ans += min(previous,current);
                previous = current;
                current = 1;
            }
        }

        ans += min(previous,current);

        return ans;
    }
};
