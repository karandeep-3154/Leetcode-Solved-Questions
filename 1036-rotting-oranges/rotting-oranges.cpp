class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<pair<int, int>, int>> q;
        int m = grid.size(), n = grid[0].size(), ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2)
                q.push({{i, j}, 0});
            }
        }

        int x[] = {0, -1, 0, 1};
        int y[] = {-1, 0, 1, 0}; 

        while(q.size()){

            auto top = q.front();
            q.pop();

            int i = top.first.first, j = top.first.second, k = top.second;

            ans = max(ans, k);

            for(int kk=0;kk<4;kk++){

                int p = i + x[kk];
                int r = j + y[kk];

                if(p>=0 and p<m and r>=0 and r<n and grid[p][r] == 1){

                    grid[p][r] = 0;
                    q.push({{p, r}, k+1});

                }

            }

        }

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == 1)
                    return -1;

        return ans;

    }
};