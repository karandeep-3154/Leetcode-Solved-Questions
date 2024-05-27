class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();

        vector<string> dp[21];

        set<string> dictionary;
        for(auto i : wordDict)
        dictionary.insert(i);

        dp[0] = {};

        for(int i=1;i<=n;i++){

            for(int j=i;j>=1;j--){

                string current = s.substr(j-1, i-j+1);
                if(dictionary.count(current)){

                    if(dp[j-1].size() == 0 and j==1){

                        dp[i].push_back(current);
                        continue;

                    }

                    for(auto k : dp[j-1]){

                        string p = k;
                        p+=" ";
                        p+=current;
                        dp[i].push_back(p);

                    }

                }

            }
        }

        return dp[n];

    }
};