class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();

        if(k>arr[0]-1)
        k-=arr[0]-1;

        else
        return k;

        if(n == 1)
        return arr[0]+k;

        for(int i=0;i<n-1;i++){

            int curDiff = arr[i+1]-arr[i]-1;

            if(curDiff<k)
            k-=curDiff;

            else
            return arr[i]+k;

        }

        return arr[n-1] + k;

    }
};