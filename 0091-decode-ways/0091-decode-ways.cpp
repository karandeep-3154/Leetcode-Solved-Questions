class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();
        
        int dp[101] = {0};
        dp[0] = 1;
        dp[1] = s[n-1] == '0' ? 0 : 1;

        for(int i=2;i<=n;i++){//dp[i] denotes ans for substring of size i from end of s

            int index = n-i;

            int a = s[index] - '0';
            int b = s[index+1] - '0';

            if(a > 0){

                if(a*10+b<=26)
                dp[i] = dp[i-2];
            dp[i]+=dp[i-1];

            }

        }

        return dp[n];

    }
};