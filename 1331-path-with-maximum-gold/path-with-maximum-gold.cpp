class Solution {
public:

    int dfs(int i, int j, vector<vector<int>>& vis, int m, int n, vector<vector<int>>& grid){

        if(i<0 or i>=m or j<0 or j>=n or vis[i][j] or grid[i][j] == 0)
        return 0;

        vis[i][j] = 1;

        int ans = grid[i][j] + max({dfs(i, j-1, vis, m, n, grid), dfs(i-1, j, vis, m, n, grid), dfs(i, j+1, vis, m, n, grid), dfs(i+1, j, vis, m, n, grid)});

        vis[i][j] = 0;
        return ans;

    }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();

        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 0)
                continue;

                vector<vector<int>> vis(m, vector<int>(n, 0));
                ans = max(ans, dfs(i, j, vis, m, n, grid));

            }
        }

        return ans;

    }
};