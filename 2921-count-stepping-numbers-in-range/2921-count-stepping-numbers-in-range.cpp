class Solution {
public:

    long long int dp[101][11][2];
    const long long int mod = 1e9+7;

    long long int getCount(string num, int i, int pre, int tight){

        if(i == num.size())
        return pre!=-1;//AS WE RETURN 1 FOR STRINGS LIKE 00321 BUT NOT 00000 AS 00000 DOESNOT SATISFY CONDITION OF ABS DIFF OF DIGITS == 1 AS IT DOESNOT HAVE ANY DIGIT OTHER THAN LEADING 0'S WHICH WE CAN CONSIDER

        if(dp[i][pre+1][tight] != -1)//tight+1 as pre can be -1 or 0,1,2...9 so after +1 it will come in range of 0 and 1...10
        return dp[i][pre+1][tight];

        long long int ub = tight ? num[i] - '0' : 9;

        long long int ans = 0;

        for(long long int j=0;j<=ub;j++){

            if(pre == -1){
                if(j==0)
                ans = (ans%mod + getCount(num, i+1, -1, 0)%mod + mod)%mod;//AS FOR EX NUM WAS 327 AND IF WE HAVE ATLEAST 1 LEADING 0 THEN IT DOESNOT MATTER WHAT FOLLOWS 0 IT WILL ALWAYS BE LESS THAN 327 SO TIGHT BECOMES 0
                else
                ans = (ans%mod + getCount(num, i+1, j, tight and j==ub)%mod + mod)%mod;
            }

            else{

                if(abs(pre-j) == 1)
                ans = (ans%mod + getCount(num, i+1, j, tight and j==ub)%mod + mod)%mod;

            }

        }

        return dp[i][pre+1][tight] = ans%mod%mod;

    }

    int check(string low){

        for(long long int i=0;i<low.size()-1;i++)
        if(abs(low[i]-low[i+1])!=1)
        return 0;

        return 1;

    }

    int countSteppingNumbers(string low, string high) {

        memset(dp, -1, sizeof(dp));        
        long long int l = getCount(low, 0, -1, 1)%mod;
        memset(dp, -1, sizeof(dp));
        long long int r = getCount(high, 0, -1, 1)%mod;

        return (check(low)%mod + r%mod-l%mod +mod)%mod;


//         //FOR CALCULATING L TO R, THE IDEA IS TO DO DP[R]-DP[L-1]. BUT, HERE IT IS NOT POSSIBLE TO DO -1 TO L AS L CAN BE A BIG STRING ITSELF. SO, FOR THAT CASE WE CALCULATING DP[R]-DP[L] WHICH WILL GIVE
// FOR L+1 TO R BUT SINCE WE WANTED FOR L TO R. SO, SIMPLY CHECK IF L FITS OUR CRITERIA AND IF IT DOES DO +1 IN OUR ANS ELSE RETURN THAT SAME ANS ONLY.


    }
};