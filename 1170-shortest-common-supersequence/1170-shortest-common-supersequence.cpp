class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {

        int m = text1.size(), n = text2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];

                else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

            }
        }

        string res = "";

		int i=m, j=n;

		while(i>0 and j>0){

			if(text1[i-1] == text2[j-1]){

				res+=text1.substr(i-1, 1);

				i--;j--;

			}

			else{

				dp[i-1][j]>dp[i][j-1] ? i-- : j--;

			}

		}

		reverse(res.begin(), res.end());

        string ans="";
        i=0;
        j=0;
        cout<<res;
        for(auto c : res){

            while(text1[i]!=c){
                ans+=text1.substr(i,1);
                i++;
            }
            
            
            while(text2[j]!=c){
                ans+=text2.substr(j,1);
                j++;
            }

            ans+=c;
            i++;j++;

        }

        if(i<m)
        ans+=text1.substr(i);
        
        if(j<n)
        ans+=text2.substr(j);

		return ans;
	
    }
};