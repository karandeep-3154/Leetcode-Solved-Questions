class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0,j=0;

        set<int> ans;
        vector<int> anss;

        while(i<nums1.size() and j<nums2.size()){

            if(nums1[i] == nums2[j]){

                ans.insert(nums1[i]);
                i++;j++;

            }
            
            else
            nums1[i]<nums2[j] ? i++ : j++;

        }

        for(auto i : ans)
        anss.push_back(i);

        return anss;

    }
};