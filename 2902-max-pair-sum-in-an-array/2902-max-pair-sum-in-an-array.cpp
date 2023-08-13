class Solution {
public:
    int maxSum(vector<int>& nums){
        int maxSum = -1;
        vector<int> buckets(10,-1);
        for(int num : nums){
            int maxDigit = 0 , N = num;
            while(N){
                maxDigit = max(maxDigit,N%10);
                N = N/10;
            }
            if(buckets[maxDigit] != -1) 
                maxSum = max(maxSum,num+buckets[maxDigit]);
            buckets[maxDigit] = max(buckets[maxDigit],num);
        }
        return maxSum;
    }
};