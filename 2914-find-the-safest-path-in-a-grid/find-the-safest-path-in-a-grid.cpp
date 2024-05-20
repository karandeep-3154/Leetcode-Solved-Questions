class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> distance(m, vector<int>(n, 1e9)), vis(m, vector<int>(n, 0));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]){
                    pq.push({0, {i, j}});
                    distance[i][j] = 0;
                    vis[i][j] = 1;
                }

            }
        }

        int a[] = {0, -1, 0, 1}, b[] = {-1, 0, 1, 0};

        while(pq.size()){

            int dis = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();

            for(int k=0;k<4;k++){
                
                int newr = i + a[k];
                int newc = j + b[k];

                if(newr>=0 and newr<m and newc>=0 and newc<n and vis[newr][newc] == 0){

                    vis[newr][newc] = 1;
                    distance[newr][newc] = 1 + dis;
                    pq.push({1+dis, {newr, newc}});

                }

            }

        }
        
        priority_queue<pair<int, pair<int, int>>> pp;
        pp.push({distance[0][0], {0, 0}});
        // vis = vector<vector<int>>(m, vector<int>(n, 0));
        vector<vector<int>> viis(m, vector<int>(n, 0));

        // for(int i=0;i<m;i++)
        // for(int j=0;j<n;j++)
        // cout<<i<<" j is "<<j<<" fsd  "<<distance[i][j]<<endl;

        while(pp.size()){
            // cout<<"Entry!"<<endl;

            int dis = pp.top().first, i = pp.top().second.first, j = pp.top().second.second;
            pp.pop();
            // cout<<dis<<" ab "<<i<<"  "<<j<<endl;

            if(i == m-1 and j == n-1)
            return dis;

            for(int k=0;k<4;k++){
                
                int newr = i + a[k];
                int newc = j + b[k];

                if(newr>=0 and newr<m and newc>=0 and newc<n and viis[newr][newc] == 0){
                    // cout<<" pushing neighbours"<<newr<<" newcc"<<newc<<endl;

                    viis[newr][newc] = 1;
                    pp.push({min(distance[newr][newc], dis), {newr, newc}});

                }

            }


        }

        return -1;

    }
};