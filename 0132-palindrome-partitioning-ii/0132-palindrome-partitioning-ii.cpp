class Solution {
public:

    bool isPalin(string &s){

        int n = s.size();

        for(int i=0;i<=n/2;i++)
        if(s[i]!=s[n-1-i])
        return false;

        return true;

    }

    void palindrome(vector<vector<int>> &pal, string &s, int n){

        for(int i=0;i<n;i++)
        pal[i][i] = 1;

        for(int i=0;i<n-1;i++)
        pal[i][i+1] = s[i] == s[i+1] ? 1 : 0;

        for(int gap = 3;gap<=n;gap++){
            for(int i=0;i<n-gap+1;i++){

                int j = i+gap-1;

                pal[i][j] = s[i] == s[j] ? pal[i+1][j-1] : 0;

            }
        }

    }

    int minCut(string s) {
        
        int n = s.size();

        if(n==0)
        return 0;

        vector<vector<int>> pal(n, vector<int>(n, 0));

        palindrome(pal, s, n);

        vector<int> dp(n+1,1e9);

        dp[0]=0;

        for(int i=1;i<=n;i++){

            for(int j=i-1;j>=0;j--){

                if(pal[j][i-1] == 1)
                dp[i] = min(dp[i], 1+dp[j]);

            }

            // cout<<i<<"    "<<dp[i]<<endl;

        }

        return dp[n]-1;

    }
};