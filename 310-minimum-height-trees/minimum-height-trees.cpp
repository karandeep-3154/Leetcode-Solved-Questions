class Solution {
public:

/*

Refer https://www.youtube.com/watch?v=tJAwo2hgMU8&pp=ygUUTWluaW11bSBIZWlnaHQgVHJlZXM%3D

 If three nodes remain after the removal process, they must be connected in a linear fashion. This means that one node is in the middle, and the other two nodes are its neighbors. In this scenario, the height of the tree is greater than in the case where only one or two nodes remain. So, ultimately we can say that any case would get 
 reduced to either 1 or 2 nodes left at the end as the final ans.

*/
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), ans;

        if(n == 1)
        return {0};

        for(auto i : edges){

            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
            indegree[i[1]]++;

        }

        queue<int> q;
        for(int i=0;i<n;i++)
            if(indegree[i] == 1)
                q.push(i);

        while(n>2){

            int sz = q.size();
            n -= sz;

            while(sz>0){

                sz--;

                int top = q.front();
                q.pop();

                for(auto i : adj[top]){

                    indegree[i]--;

                    if(indegree[i]==1)
                    q.push(i);

                }

            }

        }

        while(q.size()){

            ans.push_back(q.front());
            q.pop();

        }

        return ans;

    }
};