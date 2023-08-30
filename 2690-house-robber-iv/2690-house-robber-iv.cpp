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
        
        int n = nums.size();//it will be of pattern FFFFFFFFFTTTTTTTTTTT as there will be a certain no. x (ans) from which k no.s are lesser present in array then if a number y is choosen lessser than x is choosen there may not be k lesser no.s but if z is choosen greater than x choosen then definetly there would be k no.s lesser than z
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