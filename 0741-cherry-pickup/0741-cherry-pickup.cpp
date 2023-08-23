class Solution {
public:

    int dp[51][51][51];

    int f(vector<vector<int>>& grid, int i1, int j1, int i2, int n){

        int j2 = i1+j1-i2;//as both persons will start from 0,0 and at each step both  move only 1 step ahead so distance of them from origin is equal

        if(i1>n-1 or j1>n-1 or j2>n-1 or i2>n-1 or grid[i1][j1] == -1 or grid[i2][j2] == -1)
        return -1e6;

        if(i1 == n-1 and j1 == n-1)//sum of i1, j1 = n-1+n-1 only possible when i2==n-1 and j2=-1 so no need to write for them also in this if condition
        return grid[i1][j1];

        if(dp[i1][j1][i2] != -1)
        return dp[i1][j1][i2];

        int curval = (i1 == i2 and j1 == j2) ? grid[i1][j1] : grid[i1][j1] + grid[i2][j2];

        int nextval = f(grid, i1+1, j1, i2+1, n);//DD
        nextval = max(nextval, f(grid, i1+1, j1, i2, n));//DR AS IF WE I1 GETS INCREMENTED AND WE DON'T INCREMENT I2 MEANS J2 IS AUTOMATICALLY INCREMENTED I.E j2(INCREMENT BY 1) = i1(INCREMENT BY 1)+j1-i2
        nextval = max(nextval, f(grid, i1, j1+1, i2, n));//RR
        nextval = max(nextval, f(grid, i1, j1+1, i2+1, n));//RD

        if(nextval<0)
        return dp[i1][j1][i2] = nextval;

// cout<<i1<<" "<<j1<<"    "<<i2<<" "<<j2<<"    "<<curval+nextval<<endl;
   
        return dp[i1][j1][i2] = curval + nextval;

    }

    int cherryPickup(vector<vector<int>>& grid) {

        memset(dp, -1, sizeof(dp));
        
        int p = f(grid, 0, 0, 0, grid.size());

        return p<0 ? 0 : p;

    }
};