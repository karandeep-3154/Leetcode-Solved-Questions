class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> leftMax(n, -1), rightMax(n, -1);

        for(int i=1;i<n;i++)
            if(max(leftMax[i-1], height[i-1]) >= height[i])
                leftMax[i] = max(leftMax[i-1], height[i-1]);

        for(int i=n-2;i>=0;i--)
            if(max(rightMax[i+1], height[i+1]) >= height[i])
                rightMax[i] = max(rightMax[i+1], height[i+1]);

        int ans = 0;

        for(int i=1;i<n-1;i++){

            if(leftMax[i] != -1 and rightMax[i] != -1)
            ans += min(leftMax[i], rightMax[i]) - height[i];
            
        }

        return ans;

    }
};