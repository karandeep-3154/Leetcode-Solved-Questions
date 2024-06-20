class Solution {
public:

    bool isPossible(vector<int>& v, int mid, int n, int m){

        m--;
        int last = 0;
        for(int i=1;i<n;i++){

            if(m == 0)
            return true;

            if(v[i] - v[last] >= mid){
                last = i;
                m--;
            }

        }

        return m == 0;

    }

    int maxDistance(vector<int>& position, int m) {
        
        long long l=0, h=1e18, ans=0, n=position.size();

        sort(position.begin(), position.end());

        while(l<=h){

            long long mid = (l+h)/2;

            if(isPossible(position, mid, n, m)){
                ans = mid;
                l = mid + 1;
            }

            else
            h = mid - 1;

        }

        return ans;

    }
};