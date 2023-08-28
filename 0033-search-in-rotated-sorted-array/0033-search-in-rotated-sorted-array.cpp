class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l=0, h=nums.size()-1;

        while(l<=h){

            int mid = (l+h)/2;

            if(nums[mid] == target)
            return mid;

            else if(nums[mid]>=nums[l]){//Left part Sorted

                if(target>=nums[l] and target<=nums[mid])
                h = mid-1;

                else
                l = mid+1;

            }

            else{//Right part is surely sorted then

                if(target>=nums[mid] and target<=nums[h])
                l = mid+1;

                else
                h = mid-1;

            }

        }

        return -1;

    }
};