class Solution {
public:
//Optmized Approach using Maps O(2^n*logn)
    void dfs(map<int, int> &mp, int index, vector<int>& nums, int n, int k, int &ans) {
        if (index == n){
            ans++;
            return;
        }

        if(!mp[nums[index]-k]){

            mp[nums[index]]++;
            dfs(mp, index + 1, nums, n, k, ans);
            mp[nums[index]]--;

        }

        dfs(mp, index + 1, nums, n, k, ans);
    }

    int beautifulSubsets(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int n = nums.size(), ans = 0;
        map<int, int> mp;
        dfs(mp, 0, nums, n, k, ans);
        return ans-1;
    
    }

};
