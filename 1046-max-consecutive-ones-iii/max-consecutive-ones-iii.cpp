class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int ans = 0, cnt0 = 0, cnt1 = 0, i=0, j=0;

        while(j<nums.size()){

            if(nums[j] == 1)
            cnt1++;

            else
            cnt0++;

            if(cnt0<=k){
            
                ans = max(ans, cnt1+cnt0);
                j++;
                continue;
            
            }

            while(cnt0 == k+1){
                if(nums[i++] == 0)
                cnt0--;
                else
                cnt1--;
            }

            j++;

        }

        return ans;

    }
};