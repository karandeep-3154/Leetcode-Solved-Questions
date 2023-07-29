class Solution {
public:

    int solve(vector<vector<int>>& grid, int i, int j){

        int m = grid.size(), n = grid[0].size();
        
        if(i<0 or j<0 or i>=m or j>=n)
        return 1e9;

        if(i == m-1 and j == n-1)
        return grid[i][j];

        return grid[i][j] + min(solve(grid,i+1,j),solve(grid,i,j+1));

    }

    int solvedp(vector<vector<int>>& grid){

        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,1e9));

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                int p = min(dp[i+1][j],dp[i][j+1]);

                if(p!=1e9)
                dp[i][j] = grid[i][j] + p;

                else 
                dp[i][j] = grid[i][j];

            }
        }
        return dp[0][0];
    }

    int minPathSum(vector<vector<int>>& grid) {
        // return solve(grid,0,0);
        return solvedp(grid);
    }
};