class Solution {
public:

    static bool cmp(string &a, string &b){
        return a.size() < b.size();
    }

    int longestStrChain(vector<string>& arr) {

        int n = arr.size();

        sort(arr.begin(), arr.end(), cmp);

        map<string, int> dp;

            int ans = 1;

            for(int i=1;i<=n;i++){

                string b = arr[i-1];

                dp[b] = 1;

                for(int j=0;j<b.size();j++){

                    string a = b.substr(0, j) + b.substr(j+1);

                    if(dp.count(a))
                    dp[b] = max(dp[b], 1 + dp[a]);

                }

                ans = max(ans, dp[b]);

            }

        return ans;
    }
};