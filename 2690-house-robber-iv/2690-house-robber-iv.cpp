class Solution {
public:
    bool helper(vector<int>&nums, int k, int mid) {
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] <= mid) {
                k--;
                i+=2;
            }
            else {
                i++;
            }
            if (k == 0) {
                return true;
            }
        }
        return k == 0;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        //traverse nums, check min and max
        int low = 1, high = INT_MAX;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (helper(nums, k, mid)) {
                ans =mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};