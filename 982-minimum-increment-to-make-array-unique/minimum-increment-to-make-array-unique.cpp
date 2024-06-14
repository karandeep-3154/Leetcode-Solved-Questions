class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        map<int, int> mp;
        sort(nums.begin(), nums.end());

        int cnt = 0, last = nums[0];

        for(auto i : nums){

            int val = max(i, last);

            while(mp.count(val) != 0)
            val++;

            last = max(last, val);

            cnt += val - i;
            mp[val]++;

        }

        return cnt;

    }
};