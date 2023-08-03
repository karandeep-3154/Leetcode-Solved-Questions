class Solution {
public:
    int dp[2002][2002];
    
    bool check(vector<int>& stones, int pre, int cur){

        if(cur == stones.size()-1)
        return true;

        if(dp[pre][cur] != -1)
        return dp[pre][cur];

        int k = stones[cur] - stones[pre];
        int ans1=0, ans2=0, ans3=0;
        //HERE, INSTEAD OF DOING LINEAR SEARCH FOR CURVAL+K,K-1 OR K+1 WE DO BINARY SEARCH AS THE GIVEN ARRAY IS ALREADY SORTED IN ASCENDING ORDER

        auto it = lower_bound(stones.begin(), stones.end(), stones[cur] + k-1);
        
        if(it!=stones.end() and k!=1 and *it == stones[cur]+k-1)
        ans1 = check(stones, cur, it-stones.begin());

        it = lower_bound(stones.begin(), stones.end(), stones[cur] + k);
        
        if(it!=stones.end() and *it == stones[cur]+k)
        ans2 = check(stones, cur, it-stones.begin());

        it = lower_bound(stones.begin(), stones.end(), stones[cur] + k+1);
        
        if(it!=stones.end() and *it == stones[cur]+k+1)
        ans3 = check(stones, cur, it-stones.begin());

        return dp[pre][cur] = ans1 or ans2 or ans3;

    }

    bool canCross(vector<int>& stones) {
        
        if(stones[1]-stones[0] != 1)
        return false;

        memset(dp, -1, sizeof(dp));
        return check(stones, 0, 1);

    }
};