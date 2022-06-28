// Problem Link: https://www.geeksforgeeks.org/minimize-steps-to-reach-k-from-0-by-adding-1-or-doubling-at-each-step/

int minOperation(int k)
{
    vector<int> dp(k + 1, 0);

    for (int i = 1; i <= k; i++) {

        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0) {
            dp[i]
                = min(dp[i],
                      dp[i / 2] + 1);
        }
    }
    return dp[k];
}
