class Solution {
public:

    int calculate(vector<int>& nums, int takefirst) {
        
        int dp[101][2];
        memset(dp, 0, sizeof(dp));

        int n = nums.size();

        if(takefirst == 1){//take first element skip last element

            dp[0][0] = 0;//not take 0th index element
            dp[0][1] = nums[0];//take 0th index element

            for(int i=1;i<n-1;i++){

                dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
                dp[i][1] = dp[i-1][0] + nums[i];
                
            }

            return max(dp[n-2][0], dp[n-2][1]);

        }

        else{//skip first element and take last element of Array

            dp[1][0] = 0;//not take 1th index element
            dp[1][1] = nums[1];//take 1th index element

            for(int i=2;i<n;i++){

                dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
                dp[i][1] = dp[i-1][0] + nums[i];
                
            }

            return max(dp[n-1][0], dp[n-1][1]);

        }

        return -1;

    }

    int rob(vector<int>& nums) {

        if(nums.size() == 0)
        return 0;

        else if(nums.size() == 1)
        return nums[0];
        
        return max(calculate(nums,0), calculate(nums,1));

    }
};