// Problem Likk: https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/
// T.C ---> O(n^2)
// S.C ---> O(n^2)

#include<bits/stdc++.h>
using namespace std;

int n,dp[1000][1000];

string str = "abcb";

 // Function return the total
// palindromic subsequence
int countPS(int i,int j)
{

    if(i>=n||j<0)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    // base cases
    if(abs(i-j)==1)
    {
        if(str[i]==str[j]) // eg-> aaa
        return dp[i][j] = 3;
        else             // eg-> ab
        return dp[i][j] = 2;
    }

    if(i==j)
    return dp[1][j] = 1;

    else if (str[i] == str[j])
return dp[i][j] = countPS(i+1, j) +
                    countPS(i, j-1) + 1;

else
return dp[i][j] = countPS(i+1, j) +
                  countPS(i, j-1) - countPS(i+1, j-1);

}

// Driver code
int main()
{
    memset(dp,-1,sizeof(dp));

    n=str.size();
    cout << "Total palindromic subsequence are : "
        << countPS(0,n-1) << endl;

    return 0;

}
