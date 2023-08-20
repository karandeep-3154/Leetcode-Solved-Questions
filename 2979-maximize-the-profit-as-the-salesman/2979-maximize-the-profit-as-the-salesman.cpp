class Solution {
public:
//REFER https://www.youtube.com/watch?v=oHhavsRd_3o

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        
        vector<int> dp(n+1, 0);

        vector<vector<pair<int, int>>> mp(n+1);

        for(auto i : offers)
        mp[i[1]+1].push_back({i[0]+1, i[2]});

        for(int i=1;i<=n;i++){

            dp[i] = dp[i-1];

            for(auto j : mp[i])
            dp[i] = max(dp[i], j.second + dp[j.first-1]);

        }

        return dp[n];

    }
};