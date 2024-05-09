class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.rbegin(), happiness.rend());

        long long ans = 0, cnt = 0;

        for(auto i : happiness){

            i -= cnt;
            cnt++;

            if(i <= 0)
            break;

            ans += i;
            k--;

            if(k == 0)
            break;

        }

        return ans;

    }
};