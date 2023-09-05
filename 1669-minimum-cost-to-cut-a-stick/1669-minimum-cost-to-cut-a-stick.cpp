class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for(int gap = 1;gap<=m-2;gap++){

            for(int i=1;i<=m-gap-1;i++){

                int j = i+gap-1;
                int ans = 1e9;

                for(int k=i;k<=j;k++)
                ans = min(ans, dp[i][k-1] + dp[k+1][j] + cuts[j+1] - cuts[i-1]);

                dp[i][j] = ans;

            }

        }

        return dp[1][m-2];

    }
};