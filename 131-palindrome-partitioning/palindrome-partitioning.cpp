class Solution {
public:

    bool isPalindrome(string &s){

        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i++] != s[j--])
            return false;
        }

        return true;

    }

    vector<vector<string>> partition(string s) {
        
        int n = s.size();

        vector<vector<string>> dp[n+1];

        dp[0] = {{}};
        // cout<<dp[1][0][0];
        for(int i=1;i<=n;i++){

            for(int j=i;j>=1;j--){

                string cur = s.substr(j-1, i-j+1);

                if(isPalindrome(cur)){

                    for(auto k : dp[j-1]){

                        vector<string> p = k;
                        p.push_back(cur);
                        dp[i].push_back(p);

                    }

                }

            }

        }

        return dp[n];

    }
};