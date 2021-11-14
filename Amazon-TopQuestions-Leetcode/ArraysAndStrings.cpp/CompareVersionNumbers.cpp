// Problem Link: https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/502/

class Solution {
public:
    int compareVersion(string version1, string version2) {

        int s1 = version1.size();
        int s2 = version2.size();

        int v1=0;
        int v2=0;

        int i=0;
        int j=0;

        while(i<s1 || j<s2){

            while(i<s1 && version1[i]!='.'){ // i<s1 takes care of the last character which does not have a '.'
                v1 = (10*v1) + (version1[i]-'0');
                i++;
            }

            while(j<s2 && version2[j]!='.'){
                v2 = (10*v2) + (version2[j]-'0');
                j++;
            }

            if(v1>v2) return 1;
            else if(v1<v2) return -1;

            v1=0;
            v2=0;

            i++;
            j++;
        }

        return 0;
    }
};
