class Solution {
public://REFER https://www.youtube.com/watch?v=WwvpuCR4MoQ

    int maxNumOfMarkedIndices(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int i = 0;
        int mid = (nums.size())/2;
        int j = mid;
        int count = 0;
        while(i<mid and j<nums.size())
        {
            if((2*nums[i])<=nums[j])
            {
                i++;
                j++;
                count+=2;
            }
            else
            {
                j++;
            }
        }
        return count;

    }
    
};