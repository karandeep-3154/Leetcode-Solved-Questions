class Solution {
public:
    int minInsertions(string s) {
        
        int dp[502][502], n = s.size();

        memset(dp, 0, sizeof(dp));

        for(int i=0;i<n-1;i++){

            dp[i][i+1] = s[i] == s[i+1] ? 0 : 1;

        }

        for(int gap=3;gap<=n;gap++){

            for(int i=0;i<=n-gap;i++){

                int j = i+gap-1;

                if(s[i] == s[j])
                dp[i][j] = dp[i+1][j-1];

                else
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;

            }

        }

        return dp[0][n-1];

    }
};