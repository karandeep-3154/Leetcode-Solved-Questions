class Solution {
public:

    int dp[500][26];

    int solve(vector<int>& nums, int i, int k, int &ans){

        if(i == 0)
        return 1;

        if(dp[i][k] != -1)
        return dp[i][k];

        solve(nums, i-1, k, ans);

        int curans = 0;

        for(int j=i-1;j>=0;j--){

            if(nums[j] == nums[i])
            curans = max(curans, solve(nums, j, k, ans));

        }

        if(k > 0){

            for(int j=i-1;j>=0;j--){

                if(nums[j] != nums[i])
                curans = max(curans, solve(nums, j, k-1, ans));

            }

        }

        ans = max(ans, curans+1);

        return dp[i][k] = curans+1;

    }

    int maximumLength(vector<int>& nums, int k) {
        
        int ans = 1;

        memset(dp, -1, sizeof(dp));

        solve(nums, nums.size()-1, k, ans);

        return ans;

    }
};