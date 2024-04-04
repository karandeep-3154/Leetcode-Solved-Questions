class Solution {
typedef long long int ll;
public:
    int minimumDistance(vector<vector<int>>& g) {

        unordered_map <ll,ll> k1,k5;
        vector<pair<int,int>> b,u;
        int n = g.size();
        for(int i=0;i<n;i++){
            b.push_back({g[i][0]+g[i][1],i});
            u.push_back({g[i][0]-g[i][1],i});
        }
        sort(b.begin(),b.end());
        sort(u.begin(),u.end());

        for(int i=0;i<n;i++){
            k1[b[i].second] = i ;
            k5[u[i].second] = i ; 
        }
        ll y = 1000000000; //RRRRR

        for(int i=0;i<n;i++){
            //remove point "i"
            ll u_id = k1[i];
            ll d1 = 0 ; 
            if(u_id==0){
                d1 = b[n-1].first - b[1].first ;
            }
            else if(u_id==n-1){
                d1 = b[n-2].first - b[0].first ; 
            }
            else
            {
                d1 = b[n-1].first - b[0].first ; 
            }

            ll v_id = k5[i];
            ll d5 = 0 ; 
            if(v_id==0){
                d5 = u[n-1].first - u[1].first ;
            }
            else if(v_id==n-1){
                d5 = u[n-2].first - u[0].first ; 
            }
            else
            {
                d5 = u[n-1].first - u[0].first ; 
            }

            ll p = max(d1,d5);
            y = min(y,p);
        }
        int t = y;
        return t;
    }
};