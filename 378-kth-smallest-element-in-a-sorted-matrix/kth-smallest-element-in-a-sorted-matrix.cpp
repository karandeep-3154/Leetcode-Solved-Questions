class Solution {
public:

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int m = matrix.size(), n = matrix[0].size();

        int low = matrix[0][0], high = matrix[m-1][n-1], ans = low;//if it was a linear sorted array, we could have taken low as 0 and high as n-1 index

        while(low <= high){

            int mid = (low + high)/2;
            int cnt = 0;

            for(int i=0;i<m;i++)
            cnt += (lower_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin());

            // cout<<" mid is "<<mid<<" cnt is "<<cnt<<endl;

            if(cnt > k-1)
            high = mid - 1;

            else{

                ans = mid;
/*Doing this as here it is TTTTFFF but here for some values although we are getting T, but they might not be present in actual, so doing ans = mid as it will ensure to find that element which really exists.

Do the dry run for k = 3 for 
matrix =
[[1,3],[2,5]] and 
matrix =
[[1,4],[2,5]]
*/
                low = mid + 1;
            }

        }

        return ans;

    }
};