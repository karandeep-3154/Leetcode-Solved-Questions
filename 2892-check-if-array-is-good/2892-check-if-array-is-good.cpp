class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i=1;i<=n-1;i++){
            if(i==n-1 && mp[i]!=2) return false;
            else if(i!=n-1 && mp[i]!=1) return false;
        }
        if(mp.size()!=n-1) return false;
        return true;
    }
};