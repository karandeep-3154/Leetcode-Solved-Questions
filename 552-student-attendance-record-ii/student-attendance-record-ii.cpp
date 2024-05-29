class Solution {
public:
int mod = 1e9+7;
using ll = long long;

ll dp[100001][3][2];

    ll calculate(int n, int cl, int ta){//consecutive late, total absent

        if(n == 0)
        return 1;

        if(dp[n][cl][ta] != -1)
        return dp[n][cl][ta];

        ll ans = 0;

        ans = (ans + calculate(n-1, 0, ta) + mod)%mod;//passing ta as 0 as we are taking current day as present here

        if(ta == 0)
        ans =(ans +  calculate(n-1, 0, 1) + mod)%mod;//marking current day as absent

        if(cl<=1)
        ans =(ans +  calculate(n-1, cl+1, ta) + mod)%mod;

        return dp[n][cl][ta] = ans;

    }

    int checkRecord(int n) {

        memset(dp, -1, sizeof(dp));

        return calculate(n, 0, 0);
        
    }
};