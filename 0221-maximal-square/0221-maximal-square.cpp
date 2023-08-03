class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int dp[301][301];
        int m = matrix.size(), n = matrix[0].size();

        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = (int)matrix[0][0] - (int)('0');

        int cnt = 0;

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(i == 0 or j == 0 or matrix[i][j] == '0')
                dp[i][j] = (int)matrix[i][j] - (int)('0');

                else{

                    dp[i][j] = 1;

                    dp[i][j] = max(dp[i][j], 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}));

                }

                 cnt = max(cnt, dp[i][j]);

            }
        }

        return cnt*cnt;


    }
};