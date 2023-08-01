class Solution {
public:
    void backtrack(int n, int k, int start, vector<int>& cur, vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i <= n; i++) {
            cur.push_back(i);
            backtrack(n, k - 1, i + 1, cur, ans);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(n, k, 1, cur, ans);
        return ans;
    }
};
