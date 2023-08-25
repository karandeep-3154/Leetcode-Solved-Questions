class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {

        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 1));

            dp[0][0] = 0;
            dp[0][1] = 0;

            int ans=1,b=1;

            for(int i=2;i<=n;i++){
                for(int j=i-1;j>0;j--){
                    
                    if(arr[j-1]<arr[i-1] and dp[i][0]<dp[j][0] + 1){

                        dp[i][0] = dp[j][0] + 1;
                        dp[i][1] = dp[j][1];

                    }

                    else  if(arr[j-1]<arr[i-1] and dp[i][0] == dp[j][0] + 1)
                    dp[i][1]+= dp[j][1];

                    
                }

                if(ans < dp[i][0]){
                    ans=dp[i][0];
                    b=dp[i][1];
                }

                else if(ans == dp[i][0])
                b+=dp[i][1];

            }

            return b;

    }
};