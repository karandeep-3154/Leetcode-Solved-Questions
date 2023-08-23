class Solution {
public:

    bool subsetSumToK(int n, int k, vector<int> &arr) {
    
        int dp[201][20001];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){

                if(j == 0)
                dp[i][j] = 1;

                else{

                    dp[i][j] = dp[i-1][j];

                    if(j-arr[i-1]>=0 and dp[i-1][j-arr[i-1]] == 1)
                    dp[i][j] = 1;

                }

            }
        }

        return dp[n][k];

    }

    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        sum = accumulate(nums.begin(), nums.end(), sum);

        if(sum%2 == 1)
        return false;

        return subsetSumToK(nums.size(), sum/2, nums);

    }
};