class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum == x)
        return nums.size();
        
        int y = sum-x;

        unordered_map<int, int> mp;
        mp[0]=-1;

        int s = 0, ans = -1;

        for(int i=0;i<nums.size();i++){

            s+=nums[i];

            if(mp.count(s-y))
            ans = max(ans, i-mp[s-y]);

            if(mp.count(s) == 0)
            mp[s] = i;

        }

        return ans == -1 ? -1 : nums.size()-ans;

    }
};