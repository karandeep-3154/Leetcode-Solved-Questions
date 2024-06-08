class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        map<int, int> mp;
        mp[0] = -1;
        
        int sum = 0;

        //a+b = c
        //if b%k == 0  => a%k == c%k
        //so we check for current sum = c, if there is any a in map

        for(int i=0;i<nums.size();i++){

            sum += nums[i];
            
            if(mp.count(sum%k) and i - mp[sum%k]>=2)
            return true;

            if(mp.count(sum%k) == 0)
            mp[sum%k] = i;

        }

        return false;

    }
};