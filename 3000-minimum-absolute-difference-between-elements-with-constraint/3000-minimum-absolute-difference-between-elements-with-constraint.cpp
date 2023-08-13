class Solution {
public:
//REFER https://www.youtube.com/watch?v=W10aQZ8f8YI
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        multiset<int> v;
        int ans=1e9;

        for(int i=x;i<nums.size();i++){

            v.insert(nums[i-x]);

            auto upperBoundIt = v.upper_bound(nums[i]);

            if(upperBoundIt != v.end()){
                
                int greater =*(upperBoundIt);
                ans = min(ans, abs(greater-nums[i]));
            }
            
            if(upperBoundIt != v.begin()){

                int smallerOrEqual = *prev(upperBoundIt);
                ans = min(ans, abs(smallerOrEqual-nums[i]));

            }
            cout<<ans<<endl;

        }

        return ans;

    }
};