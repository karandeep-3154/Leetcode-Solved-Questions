class Solution {
public:
    bool isMatch(string s, string p) {
        
        int dp[2001][2001];

        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;

        int i=-1;
        for(i=0;i<p.size();i++)
        if(p[i]!='*')
        break;

        cout<<i;

        if(i!=-1){

            i--;
            
            while(i>=0){

                for(int j=0;j<=s.size();j++)
                dp[i+1][j] = 1;

                i--;
                
            }
            
        }
        
        for(int i=1;i<=p.size();i++){
            for(int j=1;j<=s.size();j++){

                if(p[i-1] != '*' and p[i-1] != '?' and p[i-1]!=s[j-1])
                continue;

                if(p[i-1] == s[j-1])
                dp[i][j] = dp[i-1][j-1];

                else if(p[i-1] == '?')
                dp[i][j] = dp[i-1][j-1];

                else{

                    for(int k=j;k>=0;k--){
                        if(dp[i-1][j-k]){
                            dp[i][j] = 1;
                            break;
                        }
                    }

                }

            }
        }
        
        return dp[p.size()][s.size()];

    }
};