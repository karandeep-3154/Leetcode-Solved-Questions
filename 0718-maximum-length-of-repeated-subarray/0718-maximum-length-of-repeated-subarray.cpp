class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));

        int a = nums1.size(), b = nums2.size(), ans = 0;

        for(int i=a-1;i>=0;i--){//dp[i][j] denotes max length of string index i to end of nums1 and similarly for nums2
            for(int j=b-1;j>=0;j--){

                if(nums1[i] == nums2[j])
                dp[i][j] = 1 + dp[i+1][j+1];

                else
                dp[i][j] = 0;//as for ex - s1 = 1123, s2 = 1324, we have to find continous common subarray not subsequence so we are not doing dp[i+1][j] + dp[i][j+1] in else as we want in continous fashion subarray

                ans = max(ans, dp[i][j]);

            }
        }
        return ans;
    }
};