// Problem Link: https://leetcode.com/problems/plus-one/submissions/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        for(int i=n-1;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
            }else{
                digits[i]++;
                return digits;
            }
        }
        // all is 9
        digits.insert(digits.begin(),1);
        return digits;
    }
};
