class Solution {
public:


    int maximumLength(vector<int>& nums, int k) {
        
        int dp[500][26], ans=1;

        memset(dp, 0, sizeof(dp));

        int n = nums.size();

        for(int i=0;i<=25;i++)
        dp[0][i] = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<=k;j++){

                int curans = 0;

                for(int p=i-1;p>=0;p--){

                    if(nums[p] == nums[i])
                    curans = max(curans, dp[p][j]);

                }

                if(j > 0){

                    for(int p=i-1;p>=0;p--){

                        if(nums[p] != nums[i])
                        curans = max(curans, dp[p][j-1]);

                    }

                }

                ans = max(ans, curans+1);

                dp[i][j] = curans+1;

            }
        }

        return ans;

    }
};