// Problem Link: https://leetcode.com/problems/lexicographical-numbers/submissions/

class Solution {

    vector<int> vs;

    void call(int n, int x){

        for(int i=x%10;i<10;i++){
            if(x>n) return;

            vs.push_back(x);
            if(x*10 <= n){
                call(n,x*10);
            }
            x++;
        }
    }
    public:
    vector<int> lexicalOrder(int n) {

        if(n==0) return {0};

        call(n,1);
        return vs;
    }
};
