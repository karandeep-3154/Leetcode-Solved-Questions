class Solution {
public:

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> ps{0};
    for (int i = 1; i < nums.size(); ++i)
        ps.push_back(ps.back() + (nums[i - 1] % 2 == nums[i] % 2));
    vector<bool> res;
    for (const auto &q : queries)
        res.push_back(ps[q[0]] == ps[q[1]]);
    return res;
}

};