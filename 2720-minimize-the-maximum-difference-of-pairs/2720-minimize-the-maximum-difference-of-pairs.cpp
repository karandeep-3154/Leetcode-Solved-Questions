class Solution {
public:

    bool isPossible(vector<int>& nums, int mid, int k){

        for(int i=0;i<=nums.size()-2;i++){

            if(nums[i+1] - nums[i] <= mid){

                i++;
                k--;

            }

            if(k == 0)
            return true;

        }

        return k==0;

    }

    int minimizeMax(vector<int>& nums, int p) {

        if(p == 0)
        return 0;
        
        int low=0, high=1e9, ans=0;

        sort(nums.begin(), nums.end());
        
        while(low<=high){
            
            int mid = (low + high)/2;
            
            if(isPossible(nums, mid, p)){
                
                ans = mid;
                high = mid-1;
                
            }
            
            else
            low = mid+1;
            
        }
        
        return ans;

    }
};