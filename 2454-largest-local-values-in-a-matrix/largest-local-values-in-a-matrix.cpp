class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m-2, vector<int>(n-2));

        for(int i=1;i<m-1;i++){

            for(int j=1;j<m-1;j++){

                ans[i-1][j-1] = max({grid[i][j], grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1], grid[i][j-1], grid[i][j+1], grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]});

            }

        }

        return ans;

    }
};