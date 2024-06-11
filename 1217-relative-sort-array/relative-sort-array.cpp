class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int, int> mp;
        for(int i=0;i<arr1.size();i++)
        mp[arr1[i]]++;

        vector<int> ans;
        for(auto i : arr2){

            while(mp[i]>0){
                ans.push_back(i);
                mp[i]--;
            }

        }

        for(auto i : mp){

            int cnt = i.second;

            while(cnt>0){
                ans.push_back(i.first);
                cnt--;
            }

        }

        return ans;

    }
};