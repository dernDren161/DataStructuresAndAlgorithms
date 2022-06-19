// Problem Link: https://leetcode.com/problems/alphabet-board-path/

class Solution {
public:
    string alphabetBoardPath(string target) {

        int r; int c; r = 0; c = 0;
        string ans = "";

        for(int i=0;i<target.size();i++){
            int m; int n;
            m = (target[i]-'a')/5; n = (target[i]-'a')%5;
            r = m - r;
            c = n - c;

            // L D U R

            if(c<0){ // L
                for(int i=0;i<(-c);i++)ans+="L";
            }

            if(r>0){ // D
                for(int i=0;i<r;i++){
                    ans += "D";
                }
            }
            if(r<0){ // U
                for(int i=0;i<(-r);i++){
                    ans += "U";
                }
            }

            if(c>0){ // R
                for(int i=0;i<c;i++)ans+="R";
            }


            ans += "!";
            r = m;
            c = n;
        }

        return ans;
    }
};
