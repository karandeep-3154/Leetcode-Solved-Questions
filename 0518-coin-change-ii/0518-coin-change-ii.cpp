class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
       int dp[301][50001];
       memset(dp, 0, sizeof(dp));

        for(int i=1;i<=coins.size();i++){
            for(int j=0;j<=amount;j++){

                if(j==0)
                dp[i][j] = 1;

                else{

                    dp[i][j] = dp[i-1][j];

                    if(j-coins[i-1] >= 0)
                    dp[i][j]+=dp[i][j-coins[i-1]];

                }

            }
        }

        return dp[coins.size()][amount];
        
    }
};