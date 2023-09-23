class Solution {
public:

    //REFER https://www.youtube.com/watch?v=hnswaLJvr6g

    int maxProduct(vector<int>& nums) {
        
        int n = nums.size(), pre = 1, suff = 1, ans=-1e9;

        for(int i=0;i<n;i++){

            pre*=nums[i];
            suff*=nums[n-i-1];

            ans = max({ans, pre, suff});

            if(pre == 0)
            pre = 1;

            if(suff == 0)
            suff = 1;

        }

        return ans;

    }
};