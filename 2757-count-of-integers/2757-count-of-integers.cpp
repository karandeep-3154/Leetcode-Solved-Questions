class Solution {
public:
        
    long long int dp[23][401][2];
    const long long int mod = 1e9+7;

    long long int getCount(string num, int minSum, int maxSum, int i, int preSum, int tight){

        if(preSum>maxSum)
        return 0;

        if(i == num.size())
        return preSum>=minSum and preSum<=maxSum;

        if(dp[i][preSum][tight] != -1)
        return dp[i][preSum][tight];

        long long int ub = tight ? num[i] - '0' : 9;

        long long int ans = 0;

        for(long long int j=0;j<=ub;j++){

            ans+=getCount(num, minSum, maxSum, i+1, preSum + j, tight and j==ub);

        }
        //cout<<num<<"  i  "<<i<<"  presum  "<<preSum<<"    tight"<<tight<<"    ans"<<ans<<endl;
        return dp[i][preSum][tight] = ans%mod%mod;

    }

    int check(string low, int minsum, int maxsum){

        int s=0;
        for(auto i : low)
        s+=(int)(i)-'0';

        return s>=minsum and s<=maxsum;
    }
    
    int count(string low, string high, int min_sum, int max_sum) {

        memset(dp, -1, sizeof(dp));        
        long long int l = getCount(low, min_sum, max_sum, 0, 0, 1)%mod;
        memset(dp, -1, sizeof(dp));
        long long int r = getCount(high, min_sum, max_sum, 0, 0, 1)%mod;
        //cout<<l<<r;
        return (check(low, min_sum, max_sum)%mod + r%mod-l%mod +mod)%mod;

    }
};