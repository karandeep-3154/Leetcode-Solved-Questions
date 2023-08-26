class Solution {
public:

     int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size(),j=0;

        stack<int> s;
        vector<int> right(n);
        
        for(int i=n-1;i>=0;i--){
            
            while(s.size() and heights[s.top()]>=heights[i])
            s.pop();
            
            if(s.size())
            right[i] = s.top()-1;

            else
            right[i]=n-1;
            
            s.push(i);
            
        }

        vector<int> left(n);
        stack<int> ss;s=ss;
        
        for(int i=0;i<n;i++){
            
            while(s.size() and heights[s.top()]>=heights[i])
            s.pop();
            
            if(s.size())
            left[i] = s.top()+1;

            else
            left[i]=0;
            
            s.push(i);
            
        }
        
        int ans=0;
               
        for(int i=0;i<n;i++)
        ans=max(ans, heights[i]*(right[i]-left[i]+1));

        return ans;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m=matrix.size(), n=matrix[0].size(), ans=0;

        vector<int> prefix(n, 0);

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                int val=matrix[i][j]-(int)'0';

                if(prefix[j]>=1 and val==0)
                prefix[j]=0;

                else
                prefix[j]+=val;

            }

            ans = max(ans, largestRectangleArea(prefix));

        }

        return ans;

    }
};