class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        
        long long p = 1;

        int n = nums.size(), max_neg = -1e8, z=0, cnt_neg=0;

        if(n == 1)
        return nums[0];

        for(auto i : nums){

            if(i == 0)
            z++;

            else if(i<0){

                max_neg = max(max_neg, i);
                cnt_neg++;
                p*=i;

            }

            else
            p*=i;

        }

        if((z == n-1 and cnt_neg == 1) or z == n)
        return 0;

        if(cnt_neg & 1)
        return p/max_neg;

        return p;

    }
};