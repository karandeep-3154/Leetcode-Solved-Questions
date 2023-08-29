class Solution {
public:

    int arrangeCoins(int n) {
        
        long low=0, high=n, ans=0;//TTTTTTTTTTTTTTTTFFFFFFFFF

        while(low<=high){

            long mid = (low+high)/2;

            long newn = (mid*(mid+1))/2;

            if(newn<=n){

                ans = mid;
                low = mid+1;

            }

            else
            high=mid-1;

        }

        return ans;

    }
};