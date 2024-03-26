class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;

        for(auto i : queries){

            vector<pair<string, int>> v;
            int t = i[1], k = i[0], cnt=0;

            for(auto j : nums){

                string ss = j.substr(j.size()-t);
                
                v.push_back({ss, cnt++});

            }

            sort(v.begin(), v.end());
            
            ans.push_back(v[k-1].second);


        }

        return ans;

    }
};