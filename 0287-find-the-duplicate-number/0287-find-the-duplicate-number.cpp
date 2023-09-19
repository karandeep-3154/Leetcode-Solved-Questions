class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(auto i : nums){

            int ind = abs(i)-1;

            if(nums[ind]<0)
            return ind+1;

            nums[ind]*=-1;

        }

        return -1;

    }
};