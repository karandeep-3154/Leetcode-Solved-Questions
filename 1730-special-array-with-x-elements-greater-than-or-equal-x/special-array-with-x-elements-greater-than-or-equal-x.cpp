class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        for(int i=0;i<=*(max_element(nums.begin(), nums.end()));i++){

            int cnt = 0;
            for(auto j : nums){

                if(j>=i)
                cnt++;

                if(cnt>i)
                break;

            }

            if(cnt == i)
            return i;

        }

        return -1;

    }
};