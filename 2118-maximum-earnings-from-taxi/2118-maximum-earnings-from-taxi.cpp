class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        vector<long long > dp(n+5, 0);

        vector<vector<pair<long long , long long >>> mp(n+5);

        for(auto i : rides)
        mp[i[1]].push_back({i[0], i[2]});

        for(int i=1;i<=n;i++){

            dp[i] = dp[i-1];

            for(auto j : mp[i])
            dp[i] = max(dp[i], j.second + i - j.first + dp[j.first]);

        }

        return dp[n];

    }
};