class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        // int dp[5001][2005];
        // memset(dp, 0, sizeof(dp));

        int n = nums.size();
        int ans = 0;

        for(int i=3;i<=n;i++){

            int last = -1;

            if(nums[i-1]-nums[i-2] != nums[i-2]-nums[i-3])
            continue;

            for(int j=i-2;j>=1;j--){

                int diff = nums[j]-nums[j-1];
                last = j;

                if(diff != nums[i-1] - nums[i-2])
                break;

            }
cout<<i<<" ans is "<<ans<<"  last is "<<last<<endl;
            ans = ans + (i-2-last);
            if(last == 1)
            ans++;
cout<<ans<<endl;
        }

        return ans;

    }
};