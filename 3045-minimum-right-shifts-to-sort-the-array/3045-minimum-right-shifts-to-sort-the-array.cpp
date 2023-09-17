class Solution {
public:

    //REFER https://www.youtube.com/watch?v=rZB-Qt4ERcM

    int minimumRightShifts(vector<int>& nums) {
        
        int n = nums.size();

        int ind = -1;

        for(int i=0;i<n-1;i++){

            if(nums[i]>nums[i+1]){

                if(ind == -1)
                ind = i;

                else//if more than one times it occurs 
                return -1;

            }

        }

        if(ind == -1)//for already sorted array
        return 0;

        if(nums[n-1]<nums[0])//checking if after joining right part (ind+1 - n) before left part the resultant array is still sorted
        return n-ind-1;

        return -1;

    }
};