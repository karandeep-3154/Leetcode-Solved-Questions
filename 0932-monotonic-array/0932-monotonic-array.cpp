class Solution {
public:

    bool inc(vector<int> &nums){

        int n = nums.size();

        for(int i=0;i<n-1;i++)
        if(nums[i]>nums[i+1])
        return false;

        return true;

    }

    bool dec(vector<int> &nums){

        int n = nums.size();

        for(int i=0;i<n-1;i++)
        if(nums[i]<nums[i+1])
        return false;

        return true;

    }

    bool isMonotonic(vector<int>& nums) {
        
        return inc(nums) or dec(nums);

    }
};