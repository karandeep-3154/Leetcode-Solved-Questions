class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int dp[1000001];

        memset(dp, 1000000, sizeof(dp));

        dp[0] = 0;

        for(auto i : coins)
        if(i<1000001)
        dp[i] = 1;

        for(int i=1;i<=amount;i++){

            for(auto j : coins){

                if(i-j>=0)
                dp[i] = min(dp[i], 1+dp[i-j]);

            }

        }

        return dp[amount]>1000000?-1:dp[amount];

    }
};