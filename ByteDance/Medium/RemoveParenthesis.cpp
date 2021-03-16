// Problem Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
    string global;

    void call(string s, int invalid, int x, string temp, int total){



        // base conditions
        if(total < 0) return;

        if(s.size()==temp.size() && s.size()-temp.size()==invalid && total==0){
            global = temp;
            return;
        }
        if(s.size() == temp.size()) return;

        if(s[x]=='(' || s[x]==')'){
            call(s,invalid,x+1,temp,total);
        }
        temp = temp + s[x];

        if(s[x]=='(') total++;
        else if(s[x]==')') total--;

        call(s,invalid,x+1,temp,total);
    }
public:
    string minRemoveToMakeValid(string s) {

    if(s.size()==0) return "";

     while(s[0]==')'){
         s.erase(0,1);
     }

    while(s[s.size()-1]=='('){
        s.erase(s.size()-1,1);
    }

        int invalid = 0;
        int sum = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                sum++;
            }else if(s[i]==')'){
                sum--;
            }
            if(sum<0){
                invalid++;
                sum = 0;
            }
        }
        invalid += sum;
        string temp = "";

        call(s,invalid,0,temp,0);

        return global;
    }
};
