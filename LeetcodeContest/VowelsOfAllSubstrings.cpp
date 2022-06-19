// Problem Link: https://leetcode.com/problems/vowels-of-all-substrings/

class Solution {
public:
    bool isVowel(char c){

        if(c=='a' || c=='e' || c=='i'||c=='o'||c=='u') return true;
        return false;
    }

    long long countVowels(string word) {

        long long ans = 0;
        long long n = word.size();

        for(int i=0;i<n;i++){
            if(isVowel(word[i])){
                ans += ((i+1)*(n-i));
            }
        }
        return ans;
    }
};
