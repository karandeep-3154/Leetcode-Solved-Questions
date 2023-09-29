// OJ: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long i = 0, j = 0, N = A.size(), ans = 1, sum = A[0];
        for (; i < N; ++i) {
            while (j < N && (j - i + 1) * A[j] - sum <= k) {
                ans = max(ans, j - i + 1);
                ++j;
                if (j < N) sum += A[j];
            }
            sum -= A[i];
        }
        return ans;
    }
};