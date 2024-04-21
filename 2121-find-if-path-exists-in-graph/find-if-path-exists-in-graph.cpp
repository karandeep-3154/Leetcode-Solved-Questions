class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        if(source == destination)
        return true;

        for(auto i : edges){
        
           adj[i[0]].push_back(i[1]);
           adj[i[1]].push_back(i[0]);
           
        }

        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while(q.size()){

            int top = q.front();
            q.pop();

            vis[top] = 1;

            for(auto neighbour : adj[top]){

                if(!vis[neighbour] and neighbour == destination)
                return true;

                if(!vis[neighbour])
                    q.push(neighbour);
                    
            }

        }

        return false;

    }
};