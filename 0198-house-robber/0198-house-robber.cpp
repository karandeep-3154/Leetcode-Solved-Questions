class Solution {
public:
    int rob(vector<int>& nums) {
        
        int dp[101][2];
        memset(dp, 0, sizeof(dp));

        int n = nums.size();

        dp[0][0] = 0;//not take 0th index element
        dp[0][1] = nums[0];//take 0th index element

        for(int i=1;i<n;i++){

            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
            
        }

        return max(dp[n-1][0], dp[n-1][1]);

    }
};