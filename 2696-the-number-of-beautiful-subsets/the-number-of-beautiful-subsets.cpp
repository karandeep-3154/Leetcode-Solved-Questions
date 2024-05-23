class Solution {
public:
    void dfs(vector<int> &cur, int index, vector<int>& nums, int n, int k, int &ans) {
        if (index == n) {
            if (!cur.empty()) {
                bool isBeautiful = true;
                for (int i = 0; i < cur.size(); i++) {
                    for (int j = i + 1; j < cur.size(); j++) {
                        if (abs(cur[j] - cur[i]) == k) {
                            isBeautiful = false;
                            break;
                        }
                    }
                    if (!isBeautiful) break;
                }
                if (isBeautiful) ans++;
            }
            return;
        }

        // Include nums[index] in the current subset
        cur.push_back(nums[index]);
        dfs(cur, index + 1, nums, n, k, ans);
        cur.pop_back();

        // Do not include nums[index] in the current subset
        dfs(cur, index + 1, nums, n, k, ans);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> cur = {};
        dfs(cur, 0, nums, n, k, ans);
        return ans;
    }
};
