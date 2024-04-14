class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        
        sort(points.begin(), points.end());

        int cnt = 1, last = points[0][0];

        for(auto i : points){

            if(i[0] - last<=w)
            continue;

            last = i[0];
            cnt++;

        }

        return cnt;

    }
};