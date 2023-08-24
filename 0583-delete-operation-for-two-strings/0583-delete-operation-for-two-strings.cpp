class Solution {
public:
    int minDistance(string a, string b) {
        
        int dp[501][501];

        dp[0][0] = 0;

        for(int i=0;i<=a.size();i++){
            for(int j=0;j<=b.size();j++){

                if(i == 0)
                dp[i][j] = j;

                else if(j == 0)
                dp[i][j] = i;

                else{

                    if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1];

                    else
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;

                }

            }
        }

        return dp[a.size()][b.size()];

    }
};