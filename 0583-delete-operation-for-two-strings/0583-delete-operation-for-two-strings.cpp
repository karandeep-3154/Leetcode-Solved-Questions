class Solution {
public:
    int minDistance(string a, string b) {
        
        int m = a.size(), n = b.size();

        int dp[501][501];

        memset(dp, 0, sizeof(dp));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];

                else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

            }
        }

        return m+n-2*dp[m][n];

    }
};