class Solution {
public:
    int strangePrinter(string s) {
        
        int dp[101][101], n = s.size();
         memset(dp, 1000000, sizeof(dp));

        for(int i=0;i<n-1;i++){

            dp[i][i] = 1;
            dp[i][i+1] = s[i] == s[i+1] ? 1 : 2;

        }

        dp[n-1][n-1] = 1;

        for(int gap = 3;gap<=n;gap++){
            for(int i=0;i<=n-gap;i++){

                int j = i+gap-1;

                for(int k=i;k<j;k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);

                if(s[i] == s[j])
                dp[i][j]--;
            }
        }

        return dp[0][n-1];

    }
};