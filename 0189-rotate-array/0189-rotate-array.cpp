// We use an extra array in which we place every element of the array at its correct
// position i.e. the number at index iii in the original array is placed at the
// index (i+k)% length of array(i + k) \% \text{ length of array}(i+k)% length of array.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            a[(i + k) % n] = nums[i];
        }
        
        for (int i = 0; i < n; i++) {
            nums[i] = a[i];
        }
    }
};
