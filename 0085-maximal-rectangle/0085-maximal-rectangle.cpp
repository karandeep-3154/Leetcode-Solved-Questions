class Solution {
public:

    int findmax(vector<int> &prefix, int val){

        int len=0, curlen=0;

        for(auto i : prefix){

            if(i == val)
            curlen++;

            else{

                len = max(len, curlen);
                curlen = 0;

            }

        }

        len = max(len, curlen);
        return len;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int ans=0, m=matrix.size(), n=matrix[0].size();

        for(int i=0;i<n;i++){
            
            vector<int> prefix(m, 0);

            for(int j=i;j<n;j++){

                for(int k=0;k<m;k++)
                prefix[k]+=matrix[k][j]-(int)'0';

                ans = max(ans, findmax(prefix, j-i+1)*(j-i+1));

            }
        }

        return ans;

    }
};