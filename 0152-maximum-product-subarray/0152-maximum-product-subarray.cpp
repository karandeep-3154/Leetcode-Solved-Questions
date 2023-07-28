class Solution {
public:
//refer https://www.youtube.com/watch?v=tHNsZHXnYd4
    int maxProduct(vector<int>& nums) {
        
        int maxi = nums[0], mini=nums[0], ans=nums[0];
        cout<<maxi<<"   "<<mini<<endl;
        for(int i=1;i<nums.size();i++){

            if(nums[i] < 0){
                int temp = maxi;
                maxi = max(nums[i], mini*nums[i]);
                mini = min(nums[i], temp*nums[i]);
            }

            else{
                maxi = max(nums[i], maxi*nums[i]);
                mini = min(nums[i], mini*nums[i]);
            }
        //cout<<"i " << i<<"    "<<maxi<<"   "<<mini<<endl;

//note: we could also just write maxi = max(nums[i], maxi*nums[i]); mini = min(nums[i], mini*nums[i]); for every i and just swap maxi and mini if nums[i]<0

            ans =  max(ans,maxi);

        }
        return ans;
    }
};