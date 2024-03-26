class Solution {
public:

    void solve(int n, int k, set<int> &s, vector<int> &cur, set<vector<int>> &ans){

        if(k == 0 and n == 0){
            vector<int> curr = cur;
            sort(curr.begin(), curr.end());
            ans.insert(curr);
            return;
        }

        if(k == 0 or n <= 0)
        return;

        for(int i=1;i<=9;i++){

            if(s.count(i))
            continue;

            s.insert(i);
            cur.push_back(i);
            solve(n-i, k-1, s, cur, ans);
            cur.pop_back();
            s.erase(i);

        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        set<vector<int>> ans;
        vector<vector<int>> anss;
        set<int> s;
        vector<int> cur;

        solve(n, k, s, cur, ans);
        
        for(auto i : ans)
        anss.push_back(i);
        
        return anss;

    }
};