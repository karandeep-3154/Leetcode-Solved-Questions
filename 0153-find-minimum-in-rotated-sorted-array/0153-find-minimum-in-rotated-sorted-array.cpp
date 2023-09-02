class Solution {
public:
    int findMin(vector<int>& nums) {

        if(nums[nums.size()-1]>=nums[0])//0 rotations i.e. given array is sorted
        return nums[0];
        
        int low = 0, high = nums.size()-1, ans = 1e9;

        while(low<=high){

            int mid = (low + high)/2;

            if(nums[low]<=nums[mid]){//1st part
                
                ans = min(ans, nums[low]);//Picking minimum of sorted half and moving to other unsorted half
                low = mid+1;
            
            }

            else{//2nd half sorted

                ans = min(ans, nums[mid]);//Picking minimum of sorted half and moving to other unsorted half
                high = mid-1;

            }

        }

        return ans;

    }
};