class Solution {
public:

    int solve(vector<int>& nums, int i, bool takelast){

        if(i >= nums.size() or (i == nums.size()-1 and takelast == false))
        return 0;

        return max(solve(nums,i+1,takelast), solve(nums,i+2,takelast) + nums[i]);

    }

    int solvedp(vector<int>& nums){

        int n = nums.size();

        vector<vector<int>> dp(n+2,vector<int>(2,0));

        for(int i=n-1;i>=0;i--){

            for(int takelast=0;takelast<2;takelast++){

                if(i == n-1 and takelast == 0)
                continue;

                dp[i][takelast] = max(dp[i+1][takelast], nums[i] + dp[i+2][takelast]);

            }

        }
        return max(dp[0][0], dp[1][1]);
    }

    int rob(vector<int>& nums) {

        if(nums.size() == 0)
        return 0;
        
        if(nums.size() == 1)
        return nums[0];
        
        // return max(solve(nums,0,false), solve(nums,1,true));
        
        return solvedp(nums);
    }
};