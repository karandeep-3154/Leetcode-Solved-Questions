class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int S, int dst, int K) {
        vector<vector<pair<int,int>>> adj(n);
         
         for(auto i : flights)
         adj[i[0]].push_back({i[1],i[2]});
         
        //priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        //as we are just moving level by level with increasing steps at each level by 1 
        //we can just use queue instead of pq as it will still not affect results as there is no need of comparision as there is uniformity in level difference
        
        queue<pair<int,pair<int,int>>> pq;
        
        vector<int> v(n,1e9);
        
        v[S] = 0;
        
        pq.push({0,{0,S}});
        
        while(pq.size()){
            
            int stops = pq.front().first;
            int dis = pq.front().second.first;
            int top = pq.front().second.second;
            pq.pop();
            
            if(stops>K)
            continue;
            
            for(auto i : adj[top]){
                
                if(v[i.first] > dis + i.second and stops<=K){//i tak ane ke steps agar atmost k ho
                    
                    v[i.first] = dis + i.second;
                    pq.push({stops+1, {v[i.first], i.first}});//now i also included in path so stops +1 as i se uske children ko steps jo ki i tak ke the and 1 jo i ab khud ek stop bna hai so steps +1
                    //steps for any node just denote steps taken to reach it excluding it
                    
                }
                
            }
            
        }
        
        return v[dst]==1e9?-1:v[dst];
    }
};