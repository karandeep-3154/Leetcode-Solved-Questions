class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();

        vector<int> ans(n, 1);

        for(int i=0;i<n-1;i++){

            if(ratings[i+1]>ratings[i] and ans[i+1]<=ans[i])
            ans[i+1]=ans[i]+1;

        }

        for(int i=n-1;i>0;i--){

            if(ratings[i-1]>ratings[i] and ans[i-1]<=ans[i])
            ans[i-1]=ans[i]+1;

        }

        int s = accumulate(ans.begin(), ans.end(), 0);

        return s;

    }
};