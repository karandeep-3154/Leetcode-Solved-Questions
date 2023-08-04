class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int dp[305]={0};
        int n = s.size();

        set<string> dict;
        for(auto i : wordDict)
        dict.insert(i);

        dp[0] = 1;

        dp[1] = dict.count(s.substr(0,1)) > 0 ? 1 : 0;

        for(int i=2;i<=n;i++){

            for(int j=i-1;j>=0;j--){

                if(dp[j] == 1 and dict.count(s.substr(j, i-j)) > 0){
                    dp[i] = 1;
                    break;
                }

            }

        }

        return dp[n];

    }
};