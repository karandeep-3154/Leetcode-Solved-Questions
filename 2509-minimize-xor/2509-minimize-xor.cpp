class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        int cnt = __builtin_popcount(num2);
        
        int ans=0;
        
        if(cnt == 0)
        return ans;

        for(int i=30;i>=0;i--){

            if(num1 & (1<<i)){
                ans|=(1<<i);
                cnt--;
            }

            if(cnt == 0)
            return ans;

        }

        for(int i=0;i<=30;i++){

            if((ans & (1<<i)) == 0){

                ans|=(1<<i);
                cnt--;

            }

            if(cnt == 0)
            return ans;

        }

        return ans;

    }
};