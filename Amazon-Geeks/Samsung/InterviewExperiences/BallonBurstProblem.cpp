// Problem Link: https://leetcode.com/problems/burst-balloons/
// Based on MCM technique

class Solution {
public:
int dp[600][600];
int solve(int arr[],int i,int j)
{
	if(i>=j)
	return 0;
	if(dp[i][j]!=-1)
	return dp[i][j];
	int mx=INT_MIN;
	for(int k=i;k<j;k++)
			{
					int temp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
					mx=max(mx,temp);
			}
return dp[i][j]=mx;
}
int maxCoins(vector& nums) {
memset(dp,-1,sizeof(dp));
int n=nums.size();
int arr[n+2];
arr[0]=1;
arr[n+1]=1;
for(int i=1;i<=n;i++)
arr[i]=nums[i-1];
return solve(arr,1,n+1);
}
};'
