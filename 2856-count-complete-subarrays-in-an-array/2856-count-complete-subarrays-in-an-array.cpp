class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        int i=0, j=0;
        map<int, int> mp;
        set<int> s;

        for(auto i : nums)
        s.insert(i);
        
        int ans=0;

        while(j<nums.size()){

            mp[nums[j]]++;

            if(mp.size() < s.size())
            j++;
            
            else{

                while(mp.size() == s.size()){
                    ans+=nums.size()-j;
                  //  cout<<i<<j<<"       "<<mp[nums[i]]<<mp[nums[j]]<<endl;
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                    i++;
                }

                j++;

            }

        }

        return ans;

    }
};