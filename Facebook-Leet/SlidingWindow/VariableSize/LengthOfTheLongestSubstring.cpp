// Problem Link: https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1

class Solution{
    public:
    int longestUniqueSubsttr(string S){

        unordered_map<char,int>m;
        int i=0;
        int j=0;
        int n=S.length();
        int maxi=0;

        while(j<n){
            m[S[j]]++;

            if(m.size()==j-i+1){
                maxi=max(maxi,j-i+1);
                j++;
            }else if(m.size()<j-i+1){

                while(m.size()<j-i+1){
                    m[S[i]]--;
                    if(m[S[i]]==0) m.erase(S[i]);
                    i++;
                }
                if(m.size()==j-i+1){  // NOTE: Unnecessary step
                    maxi=max(maxi,j-i+1);
                }
               j++;
            }
        }

        return maxi;

    }
};
