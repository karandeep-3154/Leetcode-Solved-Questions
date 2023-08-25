class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int m=s1.size(), n=s2.size();

        if(s3.size() != m+n)
        return false;

        int dp[101][101];
        memset(dp, 0, sizeof(dp));

        dp[m][n] = 1;

        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){

                int k=i+j;

                if(i == m and j!=n)
                dp[i][j] = s3.substr(k) == s2.substr(j);

                else if(j == n and i!=m)
                dp[i][j] = s3.substr(k) == s1.substr(i);

                else if(i<m and j<n){

                    if(s1[i] == s2[j] and s1[i] == s3[k])
                    dp[i][j] = dp[i+1][j] or dp[i][j+1];

                    else if(s1[i] == s3[k])
                    dp[i][j] = dp[i+1][j];

                    else if(s2[j] == s3[k])
                    dp[i][j] = dp[i][j+1];

                }

            }
        }

        return dp[0][0];

    }
};