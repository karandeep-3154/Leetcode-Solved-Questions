class Solution {
public:
// Let's see how these base cases play out in the dynamic programming process:

// When the remaining soup consists of only soup A, there is a 100% probability (1) that soup A will be empty first. Hence, for all i > 0 and j = 0, the value of dp[i][0] is set to 1.

// When the remaining soup consists of only soup B, there is a 0% probability (0) that soup A will be empty first. Hence, for all i = 0 and j > 0, the value of dp[0][j] is set to 0.

// When both types of soup have run out (i = 0 and j = 0), the answer includes half the probability that A and B become empty at the same time. Hence, dp[0][0] is set to 1/2.

// We know that as N increase, the probability will converge to 1.0 However, we need to decide the threshold of N. Then we can use the following simulation with binary search to find such N. If you run the following code with N=4800, the ans will be 0.99999, for N=4801, the answer is 1.0 and also its clearly visible that there is no case for a=0 and b=b-something. so its sure that it will converge for larger n and some threshold must exist which is 4800 in this case.

    double soupServings(int n) {

        if(n>=4800)
        return 1.0;
        
        double dp[n+1][n+1];
        memset(dp, 0.0, sizeof(dp));

        for(int i=1;i<=n;i++)
        dp[0][i] = 1.0;

        dp[0][0] = 0.5;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){

                int p=0,q=0;

                double a = i-100>=0 ? dp[i-100][j]:dp[0][j];
                
                if(i-75>0)
                p=i-75;
                if(j-25>0)
                q=j-25;

                double b = dp[p][q];

                p=0;q=0;
                if(i-50>0)
                p=i-50;
                if(j-50>0)
                q=j-50;

                double c = dp[p][q];

                p=0;q=0;
                if(i-25>0)
                p=i-25;
                if(j-75>0)
                q=j-75;

                double d = dp[p][q];

                dp[i][j] = 0.25*(a+b+c+d);

            }
        }

        return dp[n][n];

    }
};