class Solution {
public:

//REFER https://www.youtube.com/watch?v=F9c7LpRZWVQ

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int a=nums1.size(), b=nums2.size();
        
        if(a>b)
        return findMedianSortedArrays(nums2, nums1);//Doing BS on shorter search space to reduce time complexity

        int total = a+b, left = total/2;

        int l = 0, h=a;

        while(l<=h){

            int mid = (l+h)/2;

            if(mid>left)
            h = mid-1;

            int req = left-mid;

            int a1 = mid==0?INT_MIN : nums1[mid-1];
            int a2 = req==0?INT_MIN : nums2[req-1];

            int b1 = mid==a?1e9 : nums1[mid];
            int b2 = req==b?1e9 : nums2[req];

            int maxi = max(a1, a2), mini = min(b1, b2);

            if(maxi<=mini){

                if(total%2 == 0)
                return (maxi+mini)/2.0;

                else
                return mini;

            }

            else if(a1>b2)
            h=mid-1;

            else
            l=mid+1;

        }

        return -1;

    }
};