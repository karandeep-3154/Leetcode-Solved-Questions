class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low = 0, high = nums.size()-1;

        if(nums.size()==1)
        return nums[0];

        while(low<=high){

            int mid = (low + high)/2;

            if((mid-1>=0 and nums[mid-1]>nums[mid]))
            return nums[mid];

            if(nums[0]<=nums[mid])//1st part
            low = mid+1;

            else//2nd part
            high = mid-1;

        }

        for(int i=0;i<nums.size()-1;i++)
        if(nums[i]>nums[i+1])
        return -1;

        return nums[0];

    }
};