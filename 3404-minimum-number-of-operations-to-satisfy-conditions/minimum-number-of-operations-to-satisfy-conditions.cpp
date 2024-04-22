class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        
        int dp[1000][10], cnt[1000][10];
        memset(cnt, 0, sizeof(dp));

        int m = grid.size(), n = grid[0].size(), tempans=1e9, ans=1e9;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt[i][grid[j][i]]++;
            }
        }

        for(int i=0;i<=9;i++){

            dp[0][i] = m-cnt[0][i];
            tempans = min(tempans, dp[0][i]);    
            
        }

        if(n == 1)
        return tempans;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=9;j++){
                dp[i][j] = 1e9;
                for(int k=0;k<=9;k++){

                    if(j == k)
                    continue;

                    dp[i][j] = min(dp[i][j], m-cnt[i][j] + dp[i-1][k]);

                    if(i == n-1)
                        ans = min(ans, dp[i][j]);

                }
            }
        }

        return ans;

    }
};