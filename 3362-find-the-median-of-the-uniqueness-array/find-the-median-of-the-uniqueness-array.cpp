class Solution {
public:
        int medianOfUniquenessArray(vector<int>& A) {
        int n = A.size();
        long long total = (long long) n * (n + 1) / 2;

        auto atmost = [&](int k) {
            long long res = 0;
            unordered_map<int, int> count;
            for (int i = 0, j = 0; j < n; j++) {
                count[A[j]]++;
                while (count.size() > k) {
                    if (--count[A[i]] == 0)
                        count.erase(A[i]);
                    i++;
                }
                res += j - i + 1;
            }
            return res;
        };

        int left = 1, right = unordered_set<int>(A.begin(), A.end()).size();
        while (left < right) {
            int k = (left + right) / 2;
            if (atmost(k) * 2 >= total)
                right = k;
            else
                left = k + 1;
        }
        return left;
    }
};