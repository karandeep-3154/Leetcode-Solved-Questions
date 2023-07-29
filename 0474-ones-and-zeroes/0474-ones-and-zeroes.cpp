class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        map<int, int> zeros, ones;
        int p = strs.size();

        for(int i=0;i<p;i++){

            for(auto j : strs[i])
            if(j=='0')
            zeros[i]++;
            else
            ones[i]++;

        }

        int dp[p+1][m+1][n+1];
        memset(dp, 0, sizeof(dp));

        for(int i=1;i<=p;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){

                    if(zeros[i-1]<=j and ones[i-1]<=k)
                    dp[i][j][k] = 1+dp[i-1][j-zeros[i-1]][k-ones[i-1]];

                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);

                }
            }

        }

        return dp[p][m][n];

    }
};