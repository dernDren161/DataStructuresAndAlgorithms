// Problem Link: https://leetcode.com/problems/minimum-number-of-frogs-croaking/

class Solution {
public:
    int minNumberOfFrogs(string s) {

        int count = 0;
        int c,r,o,a,k;
        c=0;r=0;o=0;a=0;k=0;

        int m = INT_MIN;

        for(int i=0;i<s.size();i++){
            if(s[i]=='c'){
                count++;
                c++;
            }else if(s[i]=='r'){
                r++;
            }else if(s[i]=='o'){
                o++;
            }else if(s[i]=='a'){
                a++;
            }else{
                k++;
                count--;
            }
            m = max(m,count);
            if(c<r || r<o || o<a || a<k) return -1;
        }

        if(c!=r || r!=o || o!=a || a!=k) return -1;
        return m;
    }
};
