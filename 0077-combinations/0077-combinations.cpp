class Solution {
public:

    void solve(int n, int k, vector<int> cur, vector<vector<int>> &ans){

        if(k == 0){

            ans.push_back(cur);
            return;

        }

        if(k>n)
        return;

        if(n == 0)
        return;

        solve(n-1, k, cur, ans);
        cur.push_back(n);
        solve(n-1, k-1, cur, ans);

    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<int> cur;
        vector<vector<int>> ans;

        solve(n, k, cur, ans);

        return ans;

    }
};