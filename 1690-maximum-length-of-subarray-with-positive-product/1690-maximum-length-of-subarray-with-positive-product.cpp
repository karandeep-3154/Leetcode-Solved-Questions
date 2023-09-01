class Solution {
public:

    int get_max(vector<int>& nums){

        int p = 1, last = 0, ans = 0;

        for(int i=0;i<nums.size();i++){

            if(nums[i] == 0){

                last = i+1;
                p=1;
                continue;

            }

            if(nums[i] > 0)
            p*=1;

            else
            p*=-1;

            if(p == 1)
            ans = max(ans, i-last+1);

        }

        return ans;

    }

    int getMaxLen(vector<int>& nums) {
        
        int product1 = get_max(nums);

        reverse(nums.begin(), nums.end());

        int product2 = get_max(nums);

        cout<<product1<<product2<<endl;

        return max(product1, product2);

    }
};