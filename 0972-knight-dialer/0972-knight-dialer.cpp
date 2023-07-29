class Solution {
public:
const int mod = 1e9+7;

    int knightDialer(int n) {

        if(n == 1)
        return 10;

        long long dp[4][3][5001] = {0};
        long long ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j][1] = 1;
            }
        }

        dp[3][0][1] = 0;
        dp[3][2][1] = 0;

        int x[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int y[] = {-2, -1, 1, 2, 2, 1, -1, -2};

        for(int moves=2;moves<=n;moves++){
            for(int i=0;i<4;i++){
                for(int j=0;j<3;j++){

                   if(i==3 and j!=1)
                   continue;

                   for(int k=0;k<8;k++){
                       
                       int a = i+x[k];
                       int b = j+y[k];

                       if(a>=0 and a<4 and b>=0 and b<3 and !(a==3 and b!=1)){
                          
                           dp[i][j][moves]+=dp[a][b][moves-1]%mod%mod;
                       }

                   }
                   
                   if(moves == n)
                   ans+=dp[i][j][n];

                }
            }
        }
        return ans%mod;
    }
};