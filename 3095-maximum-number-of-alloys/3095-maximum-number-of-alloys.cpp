class Solution {
public:

    using ll = long long;

    int find(int n, vector<int> &comp, vector<int>& stock, vector<int>& cost, int budget, int n_alloys){

        ll t_cost = 0;

        for(int i=0;i<n;i++){

            ll quantity = 1ll*n_alloys*comp[i]-stock[i];

            if(quantity<0)//stock[i] is big amount already present and fulfils all demands
            quantity = 0;

            t_cost+=quantity*cost[i];

        }

        return t_cost<=budget;

    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        
        ll ans = 0;

        for(int i=0;i<k;i++){

            ll low = 0, high = 1e9, curans = 0;

            while(low<=high){

                int mid = (low+high)/2;

                int res = find(n, composition[i], stock, cost, budget, mid);

                if(res == 1){

                    curans = mid;
                    low = mid+1;

                }

                else
                high = mid-1;

            }

            ans = max(ans, curans);

        }

        return ans;

    }
};