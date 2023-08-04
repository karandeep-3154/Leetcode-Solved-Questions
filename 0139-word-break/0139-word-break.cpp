class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int dp[305][305], n = s.size();

        memset(dp, 0, sizeof(dp));

        set<string> dict;
        for(auto i : wordDict)
        dict.insert(i);

        for(int i=0;i<n;i++){

            if(dict.count(s.substr(i, 1)) > 0)
            dp[i][i] = 1;

        }
        
        for(int gap=2;gap<=n;gap++){

            for(int i=0;i<=n-gap;i++){

                int j = i+gap-1;

                if(dict.count(s.substr(i, j-i+1)) > 0){

                    dp[i][j] = 1;
                    continue;

                }

                for(int k=i;k<=j;k++){

                    if(dp[i][k] == 1 and (k == j or dict.count(s.substr(k+1, j-k)) > 0)){
                        dp[i][j] = 1;
                        break;
                    }
                }

                //cout<<i<<"  "<<j<<"     "<<dp[i][j]<<endl;

            }

        }

        return dp[0][n-1];

    }
};