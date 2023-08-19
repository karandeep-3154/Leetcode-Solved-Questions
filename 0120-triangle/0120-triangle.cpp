class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int dp[201][201];
        memset(dp, 1000000, sizeof(dp));

        int n = triangle.size(), ans = 1e9;

        dp[1][1] = triangle[0][0];

        if(n == 1)
        return dp[1][1];

        for(int i=2;i<=n;i++){

            for(int j=1;j<=i;j++){

                if(j>1)
                dp[i][j] = min(dp[i][j], triangle[i-1][j-1] + dp[i-1][j-1]);

                dp[i][j] = min(dp[i][j], triangle[i-1][j-1] + dp[i-1][j]);

                if(i == n)
                ans = min(ans, dp[i][j]);

                // cout<<i<<"  "<<j<<"     "<<dp[i][j]<<endl;

            }

        }

        return ans;

    }
};