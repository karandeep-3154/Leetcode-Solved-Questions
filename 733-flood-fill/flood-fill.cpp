class Solution {
public:

    bool check(int i, int j, int n, int m){

        if(i<0 or i>n-1 or j<0 or j>m-1)
        return false;

        return true;

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size(), m = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int col = image[sr][sc];
        
        if(col == color)
        return image;

        while(q.size()){

            auto top = q.front();
            q.pop();

            int curr = top.first;
            int curc = top.second;
            image[curr][curc] = color;

            if(check(curr+1,curc,n,m) and image[curr+1][curc] == col )
            q.push({curr+1,curc});

            if(check(curr-1,curc,n,m) and image[curr-1][curc] == col )
            q.push({curr-1,curc});

            if(check(curr,curc+1,n,m) and image[curr][curc+1] == col   )
            q.push({curr,curc+1});

            if(check(curr,curc-1,n,m) and image[curr][curc-1] == col )
            q.push({curr,curc-1});


        }
        return image;
    }
};