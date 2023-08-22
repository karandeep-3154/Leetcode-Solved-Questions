class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

    int belowTCount = 0, tCount = 0, n=nums.size();
    
    for (int i = 0; i < n; i++) {
        if (nums[i] < target)
            belowTCount++;
        else if (nums[i] == target)
            tCount++;
    }
    
    vector<int> ans;

    for (int t = 0; t < tCount; t++) {
        ans.push_back(belowTCount++);
    }
    
    return ans;
    
    }
};