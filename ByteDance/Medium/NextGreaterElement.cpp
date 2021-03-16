// Problem Link: https://leetcode.com/problems/next-greater-element-iii/

class Solution {
public:
    int nextGreaterElement(int n) {

        string temp = to_string(n);
        // "12"
        int x = temp.length();
        // 4321
        // a[i]<a[i+1]

        int k = -1;

        for(int i=x-2;i>=0;i--){
            if(temp[i]<temp[i+1]){
                k = i;
                break;
            }
        }

        if(k==-1) return -1;

        for(int i=x-1;i>=0;i--){
            if(temp[i]>temp[k]){
                swap(temp[i],temp[k]);
                break;
            }
        }

        reverse(temp.begin()+(k+1),temp.end());

        stringstream f(temp); // alternative to 'stoi'
        int t = 0;
        f >> t;
        return t;
    }
};
