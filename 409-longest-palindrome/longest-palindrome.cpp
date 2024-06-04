class Solution {
public:
    int longestPalindrome(string s) {
        
        int ans = 0;
        int freq[58] = {0};
    
        for(auto i : s)
        freq[i-'A']++;

        bool flag = 0;

        for(int i=0;i<58;i++){

            if(freq[i]%2 == 0)
            ans += freq[i];

            else{
            
                ans += freq[i] - 1;
                if(!flag){
                    flag = 1;
                    ans++;
                }    
            }

        }

        return ans;

    }
};