// The idea is to move each num[i] k steps forward until it wraps around, then repeat that for the indices not yet covered.

// For example, when the array size is 9 and k is 3:

// Move index 0 -> 3 -> 6 (index 6 wraps back to 0 so we stop)
// Move index 1 -> 4 -> 7
// Move index 2 -> 5 -> 8
// When array size is 10 and k is 3:

// Move index 0 -> 3 -> 6 -> 9 -> 2 -> 5 -> 8 -> 1 -> 4 -> 7 (7 wraps back to 0)

// Every index is visited exactly once, so the time is O(n).

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        k = k % nums.size();
        int count = 0;
        for (int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
};
