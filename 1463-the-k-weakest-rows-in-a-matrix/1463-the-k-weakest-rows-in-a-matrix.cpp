class Solution {
public:
//REFER https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/solutions/1201679/c-python3-no-heap-no-bs-simple-sort-99-20/?envType=daily-question&envId=2023-09-18

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int n=mat[0].size();
        for(int i=0; i<mat.size(); i++){
            mat[i].push_back(i);
        }
        sort(mat.begin(), mat.end());
        vector<int> ans(k);
        for(int i=0; i<k; i++){
            ans[i]=mat[i][n];            
        }
        return ans;
        
    }
};