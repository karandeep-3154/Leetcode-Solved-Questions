class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        int n = s.size();

        set<string> dict;
        for(auto i : dictionary)
        dict.insert(i);

        vector<int> dp(n+1, 1e9);

        dp[0] = 0;
        if(dict.count(s.substr(0,1)))
        dp[1] = 0;
        else
        dp[1] = 1;

        for(int i=2;i<=n;i++){

            dp[i] = 1+dp[i-1];

            for(int j=i-1;j>=0;j--){

                if(dict.count(s.substr(j, i-j)))
                dp[i] = min(dp[i], dp[j]);

            }

            cout<<i<<"  "<<dp[i]<<endl;

        }

        return dp[n];

    }
};