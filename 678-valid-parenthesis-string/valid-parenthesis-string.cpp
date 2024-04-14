class Solution {
public:

// REFER https://youtu.be/Pno2hATcwHA?si=1nY-uYZM1pyC-WbR 

// https://www.youtube.com/watch?v=Ah8xgpoGIUE&t=1834s&pp=ygUYdmFsaWQgcGFyZW50aGVzaXMgc3RyaW5n
    
    bool checkValidString(string s) {
        
        int dp[101][102], n = s.size();//dp[i][j] denotes string of from index i till index n-1 with current opened brackets as j
        memset(dp, 0, sizeof(dp));
        dp[n][0] = 1;

        // for(int i=1;i<=n;i++)
        // dp[i][0] = 1;//if no. of open brackets are 0 for any size of string s
//above thing cannot always hold true as if string is )) and initially open brackets are 0, so we would say it is true but no, )) is still invalid. So, we are checking its validity as well 

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=n;j++){

                if(s[i] == '(')
                dp[i][j] = dp[i+1][j+1];

                else if(s[i] == ')'){

                    if(j>0)
                    dp[i][j] = dp[i+1][j-1];

                }

                else{

                    if(j>0)
                    dp[i][j] = dp[i+1][j-1] or dp[i+1][j] or dp[i+1][j+1];

                    else
                    dp[i][j] = dp[i+1][j] or dp[i+1][j+1];

                }
            }
        }

        return dp[0][0];//as we want ans for string of size n from 0 to n-1 when initially cnt of opened brackets are 0

    }
};