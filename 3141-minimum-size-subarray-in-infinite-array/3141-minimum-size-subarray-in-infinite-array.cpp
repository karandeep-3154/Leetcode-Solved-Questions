class Solution {
public:

    using ll = long long;
    
    int find(vector<int>& nums, int target){
        
        unordered_map<int, int> mp;

        mp[0]=-1;

        int n = nums.size();

        ll s=0, ans=1e9;

        for(int i=0;i<2*n;i++){

            s+=nums[i%n];

            if(mp.count(s-target) and i-mp[s-target]<ans)
            ans = i-mp[s-target];

            mp[s] = i;

        }
        
        return ans;
        
    }
    
    int minSizeSubarray(vector<int>& nums, int target) {        
        
        ll tsum = 0;
        
        for(auto i : nums)
        tsum+=i;

        ll n = nums.size(), cnt=0;
        
        if(target>=tsum)
        cnt+=target/tsum;//this will eliminate sum of full array present in target

        //now we just have to find the min size subarrat in nums+nums array
        //dry run for few examples for more clarity

        target%=tsum;

        if(target == 0)
        return cnt*n;

        ll c = find(nums, target);

        if(c<n)
        return cnt*n+c;

        return -1;
        
    }
};