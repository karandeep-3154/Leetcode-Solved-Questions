class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        // vector<int> left(n);
        // vector<int> right(n);

        // left[0] = 1;
        // right[n-1] = 1;

        // for(int i=1;i<n;i++)
        // left[i] = left[i-1]*nums[i-1];

        // for(int i=n-2;i>=0;i--)
        // right[i] = right[i+1]*nums[i+1];

        // vector<int> ans(n);
        
        // for(int i=0;i<n;i++)
        // ans[i] = left[i]*right[i];

        // return ans;

        vector<int> ans(n,1);
        int p=1;
        for(int i=0;i<n;i++){
            ans[i] = p;
            p*=nums[i];
        }
        p=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*= p;
            p*=nums[i];
        }

        return ans;

    }
};