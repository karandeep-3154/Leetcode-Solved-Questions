class Solution {
public:
  
    int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n+1, 1);

		dp[0]=0;

		int ans = 1;

		for(int i=2;i<=n;i++){
			for(int j=i-1;j>0;j--){
				
				if(arr[j-1]<arr[i-1])
				dp[i] = max(dp[i], 1 + dp[j]);
				
			}

			ans = max(ans, dp[i]);

		}

		return ans;

    }
};