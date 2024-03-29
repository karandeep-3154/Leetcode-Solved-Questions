class Solution {
    int i,j;
    int m,n;
public:
    Solution(int m, int n) {
        i = 0;
        j = 0;
        this -> m = m;
        this -> n = n;
    }
    
    vector<int> flip() {
        vector<int> ans =  {i,j};
        j = (j + 1);
        if(j == n){
            j = 0;
            i += 1;
            if(i == m){
                i = 0;
            }
        }
        return ans;
    }
    
    void reset() {
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */