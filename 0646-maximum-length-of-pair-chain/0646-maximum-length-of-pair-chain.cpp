class Solution {
public:
    
    int solveso(vector<vector<int>>& p, int n){

           vector<int> next(n+1,0);
           vector<int> cur(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                
                int include=0;
                if( j==-1 || p[j][1]<p[i][0])
                  include = 1 + next[i+1];
        
                int exclude = next[j+1];
        
                 cur[j+1] = max(include,exclude);
            }
            next=cur;
        }
        return next[0];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        return solveso(pairs, pairs.size());
    }
};