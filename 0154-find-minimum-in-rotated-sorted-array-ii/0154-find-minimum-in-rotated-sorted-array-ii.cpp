class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low = 0, high = nums.size()-1, ans = 1e9;

        if(nums.size() == 1)
        return nums[0];

        if(nums.size() == 2)
        return min(nums[nums.size()-1], nums[0]);

        while(low<=high){

            int mid = (low + high)/2;

            ans = min(ans, nums[mid]);//for cases like nums=[33333333333333]
            
            if(nums[mid] == nums[low] and nums[mid] == nums[high]){

                low++;
                high--;
                continue;

            }

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