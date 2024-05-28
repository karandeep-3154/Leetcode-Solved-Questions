class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int maxLength = 0, cost=0;
        int i=0, j=0;

        while(j<s.size()){

            cost+=abs(s[j]-t[j]);

            if(cost<=maxCost){

                maxLength = max(maxLength, j-i+1);
                j++;
                continue;

            }

            while(cost>maxCost)
            cost = cost - abs(s[i]-t[i++]);

            maxLength = max(maxLength, j-i+1);
            j++;

        }

        return maxLength;

    }
};