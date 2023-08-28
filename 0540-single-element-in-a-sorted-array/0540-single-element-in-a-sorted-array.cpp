class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();

        if(n == 1)
        return nums[0];

        if(nums[0] != nums[1])
        return nums[0];

        if(nums[n-2] != nums[n-1])
        return nums[n-1];

        int l=1, h=n-2;

        while(l<=h){

            int mid = (l+h)/2;

            if(nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1])
            return nums[mid];

            else if(mid % 2 == 0){//even index

                if(nums[mid+1] == nums[mid])
                l=mid+1;

                else
                h=mid-1; 

            }

            else{

                if(nums[mid-1] == nums[mid])
                l=mid+1;

                else
                h=mid-1;

            }

        }

        return -1;

    }
};