class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size(), n2=nums2.size();

        if(n2<n1)
        return findMedianSortedArrays(nums2, nums1);

        int left_cnt = (n1+n2+1)/2;

        int low=0, high=min(left_cnt, n1);

        while(low<=high){

            int mid1 = (low+high)/2;
            int mid2 = left_cnt-mid1;

            int l1=-1e9, l2=-1e9, r1=1e9, r2=1e9;

            if(mid1-1>=0)
            l1=nums1[mid1-1];

            if(mid2-1>=0)
            l2=nums2[mid2-1];

            if(mid1<n1)
            r1=nums1[mid1];

            if(mid2<n2)
            r2=nums2[mid2];

            if(l1<=r2 and l2<=r1){

                if((n1+n2)%2==0)
                return (double)(max(l1,l2) + min(r1,r2))/(2.0);

                else
                return max(l1,l2);

            }

            else if(l1>r2)
            high = mid1-1;

            else
            low = mid1+1;

        }

        return -1;

    }
};