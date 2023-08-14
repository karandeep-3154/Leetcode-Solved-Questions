class Solution {
public:
//REFER
// https://www.youtube.com/watch?v=WIrA4YexLRQ&t=1s FOR PARTITONING/QUICK SORT
//  https://www.youtube.com/watch?v=fnbImb8lo88&t=151s FOR QUICK SELECT
    int partition(vector<int>& nums,int left,int right){
        int pivot=nums[left];
        int l=left+1;
        int r=right;
        while(l<=r){
            if(pivot > nums[l] && pivot < nums[r]){
                swap(nums[l++],nums[r--]);
            }
            if(nums[l]>=pivot){
                l++;
            }
            if(nums[r]<=pivot){
                r--;
            }
        }
        swap(nums[left],nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left=0,right=nums.size()-1,ans;
        while(1){
            int idx=partition(nums,left,right);
            if(idx==k-1){
                ans=nums[idx];
                break;
            }
            if(idx<k-1){
                left=idx+1;
            }else{
                right=idx-1;
            }
        }
        return ans;
    }
};