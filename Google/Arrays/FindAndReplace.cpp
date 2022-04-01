// Problem Link: https://leetcode.com/explore/interview/card/google/59/array-and-strings/3057/

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {

        int k = indices.size();
        vector<string>patterns(s.size());

        for(int i=0;i<k;i++){
            patterns[indices[i]] = targets[i];
        }

        vector<int>l(s.size(),0);

        for(int i=0;i<k;i++){
            int len = sources[i].size();

            string temp = "";

            for(int j=indices[i];j<s.size();j++){
                temp += s[j];
                if(temp.size()==len) break;
            }
            if(temp==sources[i]){
                l[indices[i]] = len; // number of elements to skip
            }
        }

        string ans = "";

        for(int i=0;i<s.size();i++){
            if(l[i]!=0){
                ans += patterns[i];
                i += (l[i]-1); // Important part
            }else{
                ans += s[i];
            }
        }

        return ans;
    }
};
