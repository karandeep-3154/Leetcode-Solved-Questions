class Solution {
public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int start = 0;
        int prefixZeros = 0;
        int currentSum = 0;
        int totalCount = 0;
        
        // Initialize end pointer
        int end = 0;
        
        // Loop through the array using while loop
        while (end < nums.size()) {
            // Add current element to the sum
            currentSum += nums[end];
            
            // Slide the window while condition is met
            while (start < end && (nums[start] == 0 || currentSum > goal)) {
                if (nums[start] == 1) {
                    prefixZeros = 0;
                } else {
                    prefixZeros += 1;
                }
                
                currentSum -= nums[start];
                start += 1;
            }
            
            // Count subarrays when window sum matches the goal
            if (currentSum == goal) {
                totalCount += 1 + prefixZeros;
            }
            
            // Move end pointer to the next element
            end++;
        }
        
        return totalCount;
    }
};