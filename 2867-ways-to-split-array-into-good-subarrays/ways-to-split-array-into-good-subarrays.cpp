class Solution {
public:

    const int mod = 1e9+7;

    int numberOfGoodSubarraySplits(vector<int>& nums) {
        
        long long dp[100001] = {0}, n = nums.size(), last = -1;

        dp[0] = 1;

        for(int i=0;i<n;i++){

            if(last == -1 and nums[i] == 1){
                dp[i] = 1;
                last = i;
                continue;
            }

            if(nums[i] == 0)
            continue;

            dp[i] = ((dp[last]%mod)*(i-last))%mod;
            last = i;
            // cout<<i<<" dp is "<<dp[i]<<endl;
                        
        }

        if(last == -1)
        return 0;

        return dp[last]%mod;

    }
};