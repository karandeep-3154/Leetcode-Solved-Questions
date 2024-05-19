class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        
        # Iterate through the array checking adjacent elements
        for i in range(len(nums) - 1):
            # Check if the parities of nums[i] and nums[i + 1] are different
            if (nums[i] % 2) == (nums[i + 1] % 2):
                return False
                
        # If we passed through all adjacent pairs and found no problem
        return True