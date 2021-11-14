// Problem Link: https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2968/
// Normal KMP
// TC: O(pat.size()) for preprocessing
// and O(pat.size()+txt.size()) for searching

class Solution {
public:

    void callForPreprocessing(int* lis, int p, string pat){
        // aaabb
        // l points to 0 and i points to 1


        int i = 1; int l = 0;
        lis[0] = 0;

        while(i<p){
            if(pat[i]==pat[l]){
                l++;
                lis[i] = l;
                i++;
            }else{ // if the index characters are not the same
                if(l==0){
                    lis[i] = 0;
                    i++;
                }else if(l != 0){
                    l = lis[l-1];
                }
            }
        }
    }

    int strStr(string haystick, string needle) {
        // needle here is the pattern
        // haystick here is the string where to be searched

        if(needle.size()==0 && haystick.size()==0) return 0;

        if(haystick.size() && needle.size()==0) return 0;
        if(haystick.size()==0 && needle.size()) return -1;

        int p = needle.size();
        int lis[p];

        callForPreprocessing(lis,p,needle);

        // Searching the patterns

        int i=0;// pointer for haystick which is the main string
        int j=0;// pointer for needle which is the pattern to be compared

        while(i<haystick.size()){
            if(haystick[i]==needle[j]){
                i++;j++;
            }
            if(j==p){
                return i-j;
                j = lis[j-1];
            }else if(i<haystick.size() && haystick[i]!=needle[j]){
                if(j==0){
                    i++;
                }else if(j!=0){
                    j = lis[j-1];
                }
            }
        }

        return -1;
    }
};
