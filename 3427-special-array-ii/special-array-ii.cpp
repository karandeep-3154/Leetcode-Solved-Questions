class Solution {
public:

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> ps(nums.size(), -1);
    ps[0] = 0;

    for (int i = 1; i < nums.size(); ++i){
        if(nums[i - 1] % 2 != nums[i] % 2)
        ps[i] = ps[i-1];

        else
        ps[i] = i;
    }
    vector<bool> res;
    for (const auto &q : queries)
        res.push_back(ps[q[0]] == ps[q[1]]);
    return res;
}

};