class Solution {
public:

//https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/

        int getMaximumConsecutive(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 1;
        for (int a: A) {
            if (a > res) break;
            res += a;
        }
        return res;
    }
};