class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int dp[100001][2];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = -1000000;

        int n = prices.size();

        for(int i=1;i<=n;i++){
            
            dp[i][0] = max(dp[i-1][0], -prices[i-1]);//buy
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i-1]);//sell

        }

        return dp[n][1];

    }
};