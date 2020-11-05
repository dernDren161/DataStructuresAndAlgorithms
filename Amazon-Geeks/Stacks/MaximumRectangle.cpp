// Problem Link: https://practice.geeksforgeeks.org/problems/max-rectangle/1#
// The code throws Run time error, could not figure out why?

int call(vector<int>&vs, int n,int m){

    // find NSR and NSL

    vector<int> v1;// would hold the indices
    vector<int> v2;

    stack<pair<int,int>>s1;  // ----> number, index
    stack<pair<int,int>>s2;

    int t = vs.size();

    // NSL
    for(int i=0;i<t;i++){
        if(s1.empty()) v1.push_back(-1);
        else if(s1.size()>0 && s1.top().first<vs[i]) v1.push_back(s1.top().second);
        else{
            while(s1.size()>0 && s1.top().first>=vs[i]) s1.pop();
            if(s1.empty()) v1.push_back(-1);
            else v1.push_back(s1.top().second);
        }

        s1.push({vs[i],i});
    }

     //NSR
     for(int i=t-1;i>=0;i--){
        if(s2.empty()) v2.push_back(t);
        else if(s2.size()>0 && s2.top().first<vs[i]) v2.push_back(s2.top().second);
        else{
            while(s2.size()>0 && s2.top().first>=vs[i]) s2.pop();
            if(s2.empty()) v2.push_back(t);
            else v2.push_back(s2.top().second);
        }

        s2.push({vs[i],i});
    }

    reverse(v2.begin(),v2.end());

    int ma = INT_MIN;

    for(int i=0;i<t;i++){
        int width = v2[i] - v1[i] -1; // is the width
        int tempo = width*vs[i];
        if(tempo > ma) ma = tempo;
    }

    return ma;
}

int maxArea(int M[MAX][MAX], int n, int m) {

    vector<int>vs;
    for(int i=0;i<m;i++) vs[i] = M[0][i];

    int x;
    x = call(vs,n,m);

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j] == 0) vs[j] = 0;
            else{
               vs[j] = vs[j] + M[i][j];
            }

        }
        int temp = call(vs,n,m);
        x = max(x,temp);
    }

    return x;
}
