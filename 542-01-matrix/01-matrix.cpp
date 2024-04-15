class Solution {
public:

    bool isvalid(int i, int j, int m, int n){

        return i>=0 and i<m and j>=0 and j<n;

    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));

        queue<pair<pair<int, int>, int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(mat[i][j] == 0){
                    
                    ans[i][j] = 0;
                    mat[i][j] = -1;
                    q.push({{i, j}, 0});

                }

            }
        }

        int x[] = {0, -1, 0, 1};
        int y[] = {-1, 0, 1, 0};

        while(q.size()){

            int i = q.front().first.first, j = q.front().first.second, dis = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){

                int row = i + x[k];
                int col = j + y[k];

                if(isvalid(row, col, m, n) and mat[row][col] == 1){

                    q.push({{row, col}, dis+1});
                    mat[row][col] = -1;
                    ans[row][col] = dis+1;

                }

            }

        }

        return ans;

    }
};