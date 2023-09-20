class Solution {
public:
int fun(int mid, int k, vector<int>& nums){

int i=1,pre=0;
k--;
int n = nums.size();

while(k>0 and i<n){

if(nums[i]-nums[pre]>=mid){
    pre=i;
    k--;
}
i++;

}

return k==0;

}
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l=0,h=1e9,ans=0;

        while(l<=h){
            int mid = (l+h)/2;
            if(fun(mid,k,price)){
                ans=mid;l=mid+1;
            }
            else
            h=mid-1;
        }return ans;

    }
};