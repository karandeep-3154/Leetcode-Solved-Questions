class Solution {
public:

    bool isPossible(vector<int>& stones, int mid){

        set<int> s;

        int pre=0, n=stones.size();

        for(int i=1;i<n;i++){

            if(stones[i] - stones[pre]<=mid)
            continue;

            else{

                if(i-1 == pre)
                return false;

                s.insert(i-1);
                pre = i-1;

            }

        }

        pre = n-1;
        for(int i=n-2;i>=0;i--){

            if(s.count(i) == 1)
            continue;

            if(stones[pre] - stones[i] <= mid){
                
                if(i == 0)
                return true;

                pre = i;
            
            }

            else
            return false;

        }

        return false;//arbitrary

    }

    int maxJump(vector<int>& stones) {
        
        int low=1, high=1e9, ans=0;
        
        while(low<=high){
            
            int mid = (low + high)/2;
            
            if(isPossible(stones, mid)){
                
                ans = mid;
                high = mid-1;
                
            }
            
            else
            low = mid+1;
            
        }
        
        return ans;

    }
};