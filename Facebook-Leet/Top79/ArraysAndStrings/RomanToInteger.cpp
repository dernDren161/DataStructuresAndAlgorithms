// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3010/

class Solution {

public:
    int call(char c){
        switch(c){
            case 'I':
            return 1;

            case 'V':
            return 5;

            case 'X':
            return 10;

            case 'L':
            return 50;

            case 'C':
            return 100;

            case 'D':
            return 500;

            case 'M':
            return 1000;
        }

        return 0;
    }
public:
    int romanToInt(string s) {
        // from Roman to integers, @RI-S

        int num = s.length();
        int res = 0;

        for(int i=0;i<num;i++){

            if(i+1 == num) {res += call(s[i]); continue;}
            if(call(s[i+1]) <= call(s[i])){
                res += call(s[i]); // call returns an integer from an equivalent Roman alphabet
            }else if(call(s[i+1]) > call(s[i])){
                res += call(s[i+1]) - call(s[i]);
                i++;
            }
        }

        return res;
    }
};
