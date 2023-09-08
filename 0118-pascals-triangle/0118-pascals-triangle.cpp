class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        vector<int> a = {1};
        ans.push_back(a);

        for(int i=1;i<numRows;i++){

            vector<int> cur;
            
            for(int j=0;j<=i;j++){

                if(j==0 or j==i)
                cur.push_back(1);

                else
                cur.push_back(ans[i-1][j-1] + ans[i-1][j]);

            }

            ans.push_back(cur);

        }

        return ans;

    }
};