class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        map<int, int> mp;
        int nz=0, no=0, ans=0;

        mp[0] = -1;

        for(int i=0;i<nums.size();i++){

            if(nums[i] == 1)
            no++;

            else
            nz++;

            int curval = nz-no;

            if(mp.count(curval) == 0)
            mp[curval] = i;

            else
            ans = max(ans, i-mp[curval]);

        }

        return ans;

    }
};