long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
{
    long long int dp[value+1];
    dp[0]=0;
    for(int i=1;i<=value;i++){
        dp[i]=INT_MAX;
    for(int j=0;j<numberOfCoins;j++){
        if(i-coins[j]>=0){
            dp[i]=min(dp[i],dp[i-coins[j]]);
        }
    }
    if(dp[i]!=INT_MAX)
        dp[i]++;
    }
    if(dp[value]!=INT_MAX)return dp[value];

    else return -1;

}
