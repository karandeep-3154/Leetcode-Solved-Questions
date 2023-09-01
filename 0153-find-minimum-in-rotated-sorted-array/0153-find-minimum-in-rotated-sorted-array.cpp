class Solution {
public:
    int findMin(vector<int>& nums) {

        if(nums[nums.size()-1]>=nums[0])//0 rotations i.e. given array is sorted
        return nums[0];
        
        int low = 0, high = nums.size()-1;

        if(nums.size()==1)
        return nums[0];

        while(low<=high){

            int mid = (low + high)/2;

            if(mid-1>=0 and nums[mid-1]>nums[mid])//there would be no case other than when rotations = 0, in which given array is sorted and nums[0] is ans which we have already handled above
            return nums[mid];

            if(nums[0]<=nums[mid])//1st part
            low = mid+1;

            else//2nd part
            high = mid-1;

        }

        return -1;

    }
};