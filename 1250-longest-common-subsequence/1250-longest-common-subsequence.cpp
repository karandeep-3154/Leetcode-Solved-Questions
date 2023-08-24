class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int dp[1001][1001];

        memset(dp, 0, sizeof(dp));

        int m = text1.size(), n = text2.size();

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];

                else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

            }
        }

        return dp[m][n];

    }
};