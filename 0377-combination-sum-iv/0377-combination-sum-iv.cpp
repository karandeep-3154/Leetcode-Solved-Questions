class Solution {
public:
   int solve(vector<int>& nums, int target){
        
        vector<long> dp(target+1,0);
        dp[0]=1;
        
        for(int i=1;i<=target;i++){
            int ans=0;
            for(int j=0;j<nums.size();j++){
                if(i-nums[j]>=0)
                ans+=dp[i-nums[j]];
            }
            dp[i]=ans;
        }
        
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
       
       return solve(nums,target);

    }
};