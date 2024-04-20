class Solution {
public:

    void dfs(int m, int n, int &lastx, int &lasty, vector<vector<int>>& land, int i, int j){

        if(i<0 or i==m or j<0 or j==n or land[i][j] == 0)
        return;

        lastx = max(lastx, i);
        lasty = max(lasty, j);
        land[i][j] = 0;

        dfs(m, n, lastx, lasty, land, i+1, j);
        dfs(m, n, lastx, lasty, land, i-1, j);
        dfs(m, n, lastx, lasty, land, i, j+1);
        dfs(m, n, lastx, lasty, land, i, j-1);

    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>> ans;

        int m = land.size(), n = land[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(land[i][j] == 1){
                    
                    int lastx = i, lasty = j;
                    dfs(m, n, lastx, lasty, land, i, j);
                    ans.push_back({i, j, lastx, lasty});

                }

            }
        }

        return ans;

    }
};