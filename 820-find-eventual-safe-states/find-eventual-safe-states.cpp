class Solution {
public:

    bool dfs(vector<vector<int>>& graph, int n, vector<int>& vis, vector<int>& pathVis, vector<int>& isSafe, int curNode){

        vis[curNode] = 1;
        pathVis[curNode] = 1;

        if(graph[curNode].size() == 0){

            isSafe[curNode] = 1;
            pathVis[curNode] = 0;
            return true;

        }

        for(auto neighbours : graph[curNode]){

            if(!vis[neighbours] and dfs(graph, n, vis, pathVis, isSafe, neighbours) == false)
            return false;

            if(pathVis[neighbours])
            return false;

        }

        pathVis[curNode] = 0;
        isSafe[curNode] = 1;
        return true;

    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();

        vector<int> vis(n, 0), pathVis(n, 0), isSafe(n, 0);

        for(int i=0;i<n;i++){

            if(!vis[i])
                dfs(graph, n, vis, pathVis, isSafe, i);

        }

        vector<int> ans;
        
        for(int i=0;i<n;i++)
            if(isSafe[i])
                ans.push_back(i);

        return ans;

    }
};