class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        int i=0,n=nums.size(),j=n-1,a=-1,b=-1;

        vector<int> ans;

        while(i<=j){

            int mid = (i+j)/2;

            if(nums[mid] == target){

                if(mid == 0 or nums[mid-1]!=target){

                    a = mid;
                    break;

                }

                else
                j=mid-1;

            }

            else if(nums[mid]>target)
            j=mid-1;

            else
            i=mid+1;

        }

        i=0, j=n-1;

        while(i<=j){

            int mid = (i+j)/2;

            if(nums[mid] == target){

                if(mid == n-1 or nums[mid+1]!=target){

                    b = mid;
                    break;

                }

                else
                i=mid+1;

            }

            else if(nums[mid]>target)
            j=mid-1;

            else
            i=mid+1;

        }
        
        if(a==-1)
        return ans;

        for(int k=a;k<=b;k++)
        ans.push_back(k);

        return ans;

    }
};