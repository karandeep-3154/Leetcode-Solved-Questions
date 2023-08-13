class Solution {
public:
    bool validPartition(vector<int>& nums) {
        
        int dp[100002]={0};

        int n = nums.size();

        
        if(n <= 1)
        return 0;

        dp[2] = nums[0] == nums[1] ? 1 : 0;

        if(n == 2)
        return dp[2];
        
        if((nums[0] == nums[1] and nums[1] == nums[2]) or (nums[1]-nums[0] == 1 and nums[2]-nums[1] == 1))
        dp[3] = 1;

        
        if(n == 3)
        return dp[3];

        for(int i=4;i<=n;i++){

            if(nums[i-1] == nums[i-2] and dp[i-2] == 1)
            dp[i] = 1;

            if(nums[i-1] == nums[i-2] and nums[i-2] == nums[i-3] and dp[i-3] == 1)
            dp[i] = 1;

            if(nums[i-1] - nums[i-2] == 1 and nums[i-2] - nums[i-3] == 1 and dp[i-3] == 1)
            dp[i] = 1;

        }
        
        return dp[n];

    }
};