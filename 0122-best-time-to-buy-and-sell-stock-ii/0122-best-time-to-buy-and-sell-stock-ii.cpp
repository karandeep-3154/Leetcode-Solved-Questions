class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int dp[30001][2], n = prices.size();//dp[i][0] denotes till ith index array size and last done operation is buy(not necessarily (i-1)th index)

        memset(dp, 0, sizeof(dp));

        dp[1][0] = 0;
        dp[1][1] = -prices[0];

        for(int i=2;i<=n;i++){// i denotes arr of size i so to access last element we will do i-1

            dp[i][0] = max(dp[i-1][1] + prices[i-1], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] - prices[i-1], dp[i-1][1]);

            cout<<"Size of array is "<<i<<"  sell  "<<dp[i][0]<<"   buy "<<dp[i][1]<<endl;

        }

        return dp[n][0];

    }
};