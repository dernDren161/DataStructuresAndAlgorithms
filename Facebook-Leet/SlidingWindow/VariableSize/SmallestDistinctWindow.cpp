class Solution{
    public:
    string call(string s1, string s2){
        int n = s1.size();
        int i=0;
        int j=0;
        unordered_map<char,int>m;
        for(char x:s2) m[x]++;
        int c = m.size();

        int ans = INT_MAX;
        string res;

        while(j<n){
            if(m.find(s1[j]) != m.end()){
                m[s1[j]]--;

                if(m[s1[j]]==0)c--;
            }

            while(c==0 && i<=j){
                if(j-i+1 < ans) {
                    ans = j-i+1;
                    res = s1.substr(i,j-i+1);
                }

                if(m.find(s1[i])!=m.end()){
                    m[s1[i]]++;
                    if(m[s1[i]]==1)c++;
                }
                i++;
            }
            j++;
        }

        return res;
    }
    string findSubString(string str)
    {
        // Your code goes here
        unordered_map<char,int>m1;
        for(char x : str)m1[x]++;
        string second = "";
        for(auto x:m1) second += x.first;

        return call(str,second);
    }
};
