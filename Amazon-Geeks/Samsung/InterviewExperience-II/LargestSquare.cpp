// Problem Link: https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=2&query=company[]SamsungproblemStatusunsolvedpage2company[]Samsung#

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;

        int t[m+1][n+1];
        memset(t,0,sizeof(t));

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(matrix[i - 1][j - 1] == '1')
                {
                    t[i][j] = min(min(t[i - 1][j - 1], t[i - 1][j]),  t[i][j - 1]) + 1;
                    res = max(res, t[i][j]);
                }
            }
        }
        return res * res;
    }
};
