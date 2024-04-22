class Solution {
public:
/*

Approach:- Dp[i][j] denotes min. operations required to make all elements of ith column
equal to j fulfilling the condition that (i-1)th col must not have elements of value j

cnt[i][j] denotes the count of element j in ith column of grid

If i am placing j at ith col, i am calculation dp[i][j] by 

1) Operations required to make rest of the elements equal to j which are already not 
(in ith col). so that will be no.of rows - freq of j in ith col => m - cnt[i][j]

2)Operations req to make (i-1)th col equal to any no. not equal to j so that no. will be k => dp[i-1][k]

*/
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