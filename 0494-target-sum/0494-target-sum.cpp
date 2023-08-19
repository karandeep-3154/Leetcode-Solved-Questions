class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int dp[21][3002]; // Since the maximum possible sum of nums can be 1000, the range of values for j is -1000 to 1000.
        int n = nums.size();
        
        memset(dp, 0, sizeof(dp));
        dp[0][1000] = 1; // To handle negative indices, shift by 1000
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2000; j++) {
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
                // if (j + nums[i - 1] <= 2000) {
                    dp[i][j] += dp[i - 1][j + nums[i - 1]];
                // }
            }
        }
        
        return dp[n][target + 1000]; // Return the count for the target sum
    }
};
