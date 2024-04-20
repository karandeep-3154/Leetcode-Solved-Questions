class Solution {
public:

    bool isSafe(int r, int c, int m, int n){
        
        return r>=0 and r<m and c>=0 and c<n;
        
    }
  
    int minimumEffortPath(vector<vector<int>>& heights) {
        
         priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<int>> effort(m, vector<int>(n, 1e9));
        
        effort[0][0] = 0;
        
        pq.push({0,{0,0}});
        
        int a[] = {0,-1,0,1}, b[] = {-1,0,1,0};
        
        while(pq.size()){
            
            auto top = pq.top();
            
            int dis = top.first;
            int r = top.second.first;
            int c = top.second.second;
            
            pq.pop();
            
            if(r == m-1 and c == n-1)
            return dis;
            
            for(int i=0;i<4;i++){
                
                int newr = r + a[i];
                int newc = c + b[i];
                
                if(isSafe(newr, newc, m, n)){
                    
                    int diff = max(dis, abs(heights[newr][newc]-heights[r][c]));
                    
                    if(effort[newr][newc] > diff){
                        
                        effort[newr][newc] = diff;
                        
                        pq.push({diff, {newr, newc}});
                    }
                }
                
            }
            
        }
        return 0;

    }
};