class Solution {
public:

using p = pair<int, pair<int, int>>;

class Compare {
    public:
       bool operator()(p a, p b){
           
           return a.first>b.first;
           
      }
};


    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<p, vector<p>, Compare> pq;
        int cnt = 1;

        int m = matrix.size(), n = matrix[0].size();

        for(int i=0;i<m;i++)
        pq.push({matrix[i][0], {i, 0}});

        while(cnt<k){

            auto top = pq.top();
            int val = top.first, i = top.second.first, j = top.second.second;
            // cout<<val<<endl;
            pq.pop();

            if(j+1<matrix[i].size())
            pq.push({matrix[i][j+1], {i, j+1}});

            cnt++;

        }

        return pq.top().first;

    }
};