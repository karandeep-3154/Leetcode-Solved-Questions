class Solution {
public:

    bool check(vector<int> v, long long mid, long long m, int k){

        int cnt=0, c=0;

        for(auto i : v){

            if(cnt == m)
            return true;

            if(i <= mid)
            c++;

            else
            c = 0;

            if(c == k){

                c=0;
                cnt++;

            }

        }

        return cnt == m;

    }

    int minDays(vector<int>& bloomDay, int m, long long k) {
        
        long long ans = 1e9, n = bloomDay.size(), l = 0, h = 1e9;

        if(m*k > n)
        return -1;

        while(l<=h){

            long long mid = (l+h)/2;

            if(check(bloomDay, mid, m, k)){

                ans = mid;
                h = mid-1;

            }

            else
            l = mid + 1;

        }

        return ans;

    }
};