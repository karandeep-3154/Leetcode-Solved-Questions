class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int dp[201][201];

        int m = grid.size(), n = grid[0].size();

        dp[0][0] = grid[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(i == 0 and j == 0)
                continue;

                dp[i][j] = 1e9;

                if(i-1>=0)
                dp[i][j] = dp[i-1][j];

                if(j-1>=0)
                dp[i][j] = min(dp[i][j], dp[i][j-1]);

                dp[i][j]+=grid[i][j];

            }
        }

        return dp[m-1][n-1];

    }
};