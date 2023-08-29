class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size(), n=matrix[0].size(), low=0, high=m*n-1;

        while(low<=high){

            int mid = (low+high)/2;

            int r=mid/n;
            int c=mid%n;

            if(matrix[r][c] == target)
            return true;

            else if(matrix[r][c] > target)
            high = mid-1;

            else
            low=mid+1;

        }

        return false;

    }
};