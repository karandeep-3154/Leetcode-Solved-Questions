class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> intersection;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0, j=0, m=nums1.size(), n=nums2.size();

        while(i<m and j<n){

            if(nums1[i] == nums2[j]){

                intersection.push_back(nums1[i]);
                i++;
                j++;

            }

            else if(nums1[i] < nums2[j])
            i++;

            else
            j++;

        }

        return intersection;

    }
};