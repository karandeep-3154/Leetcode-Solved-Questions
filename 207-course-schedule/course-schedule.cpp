class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto i : prerequisites){

            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;

        }

        queue<int> q;
        vector<int> topo, vis(numCourses, 0);

        for(int i=0;i<numCourses;i++)
            if(indegree[i] == 0)
                q.push(i);
        
        while(q.size()){

            int top = q.front();
            q.pop();

            topo.push_back(top);

            vis[top] = 1;

            for(auto i : adj[top]){

                if(!vis[i]){

                    indegree[i]--;
                    if(indegree[i] == 0)
                        q.push(i);

                }

            }

        }

        return topo.size() == numCourses;

    }
};