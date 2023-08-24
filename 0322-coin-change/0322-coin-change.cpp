class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int dp[13][10001];

        dp[0][0] = 1;
        for(int j=1;j<=amount;j++)
        dp[0][j] = 100000;

        for(int i=1;i<=coins.size();i++){
            for(int j=0;j<=amount;j++){

                if(j==0)
                dp[i][j] = 0;

                else{

                    dp[i][j] = dp[i-1][j];

                    if(j-coins[i-1] >= 0)
                    dp[i][j] = min(dp[i][j], 1+dp[i][j-coins[i-1]]);

                }

            }
        }

        return dp[coins.size()][amount] == 100000 ? -1 : dp[coins.size()][amount];

    }
};