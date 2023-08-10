class Solution {
public:

//REFER https://www.youtube.com/watch?v=qVfjmkL1naw&t=597s

    int deleteAndEarn(vector<int>& nums) {

        int dp[10001][2], freq[10001] = {0}, maxi = 0;

        memset(dp, 0, sizeof(dp));

        for(auto i : nums){

            freq[i]++;
            maxi = max(maxi, i);

        }

        for(int i=1;i<=maxi;i++){

            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = freq[i]*i + dp[i-1][0];

        }



        return max(dp[maxi][0], dp[maxi][1]);

    }
};