class Solution {
public:

class DisjointSet {
public: 
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

int convert(int a, int b, int m, int n){

    return a*n+b;

}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        DisjointSet ds(n*m);

        int a[] = {0, -1, 0, 1}, b[] = {-1, 0, 1, 0}, cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 0){
                    cnt++;
                    continue;
                }

                for(int k=0;k<4;k++){

                    int newr = i + a[k], newc = j + b[k];

                    if(newr>=0 and newr<m and newc>=0 and newc<n and grid[newr][newc])
                    ds.unionBySize(convert(i, j, m, n), convert(newr, newc, m, n));

                }

            }
        }

        if(cnt == m*n)
        return 0;

        int maxArea = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(ds.parent[convert(i, j, m, n)] == convert(i, j, m, n))
                maxArea = max(maxArea, ds.size[convert(i, j, m, n)]);

            }
        }

        return maxArea;

    }
};