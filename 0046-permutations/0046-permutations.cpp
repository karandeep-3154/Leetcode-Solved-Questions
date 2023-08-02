class Solution {
public:

    void solve(vector<int>& nums, int i, vector<int>cur, set<vector<int>>& s){

        if(i == nums.size()){
            s.insert(cur);
            return;
        }

        for(int j=i;j<nums.size();j++){

            swap(nums[i],nums[j]);
            cur.push_back(nums[i]);

            solve(nums,i+1,cur,s);
            cur.pop_back();

            swap(nums[i],nums[j]);

        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> p;

        solve(nums,0,p,s);

        for(auto  i  : s)
        ans.push_back(i);

        return ans;


    }
};