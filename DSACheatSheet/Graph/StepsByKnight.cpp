// Problem Link: https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#
// T.C : O(n^2)

class Solution
{
    public:

    bool safe(int i, int j, int n){
        return i>0 && i<=n && j>0 && j<=n;
    }

    int callBFS(vector<int>&k, vector<int>&t, int n){


        queue<pair<pair<int,int>,int>> qs; // {{i,j},dist}
        qs.push({{k[0],k[1]},0});

        int row[8] = {2,1,-1,-2,-2,-1,1,2};
        int col[8] = {1,2,2,1,-1,-2,-2,-1};



        int truth[n+1][n+1];    // NOTE: NOTICE THIS THING, ITS SIZE IS 'n+1' instead of 'n'
        memset(truth,0,sizeof(truth));

        while(!qs.empty()){


            int a = qs.front().first.first;
            int b = qs.front().first.second;
            qs.pop();

            if(a==t[0] && b==t[1]) return qs.front().second;  // NOTE: Accessing the distance here

            for(int i=0;i<8;i++){
                if(safe(a+row[i],b+col[i],n) && !truth[a+row[i]][b+col[i]]){
                    qs.push({{a+row[i],b+col[i]},qs.front().second+1}); // NOTE: Adding the distance here
                    truth[a+row[i]][b+col[i]] = 1;
                }
            }
        }
        return -1;
    }

	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    if(KnightPos==TargetPos) return 0;

	    return callBFS(KnightPos,TargetPos,N);
	}
};
