class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k==0)
        return 0;

        int p=1, i=0, j=0, ans=0;

        while(j<nums.size()){

            // cout<<i<<"  "<<j<<endl;

            // cout<<"Ans1 : "<<ans;

            p*=nums[j];

            if(p<k){
                ans+=j-i+1;
                j++;
            }

            else{

                while(p>=k and i<=j){
                    p/=nums[i];
                    i++;
                }

                if(i<=j)
                ans+=j-i+1;

                j++;

            }

            //cout<<"     Ans2 : "<<ans<<endl;

        }
        return ans;
    }
};