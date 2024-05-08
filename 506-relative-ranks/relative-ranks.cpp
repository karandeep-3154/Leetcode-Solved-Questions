class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<pair<int, int>> scores;
        int n = score.size();

        for(int i=0;i<n;i++)
        scores.push_back({score[i], i});

        sort(scores.begin(), scores.end(), greater<pair<int, int>>());

        vector<string> ans(n);

        if(0<n)
        ans[scores[0].second] = "Gold Medal";
        if(1<n)
        ans[scores[1].second] = "Silver Medal";
        if(2<n)
        ans[scores[2].second] = "Bronze Medal";

        for(int i=3;i<n;i++)
        ans[scores[i].second] = to_string(i+1);

        return ans;

    }
};