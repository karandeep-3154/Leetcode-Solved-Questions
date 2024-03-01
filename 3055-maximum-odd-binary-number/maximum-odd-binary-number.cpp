class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int cnt = 0;

        for(auto i : s)
        if(i == '1')
        cnt++;

        string ans = "";

        for(int i=1;i<=cnt-1;i++)
        ans = ans + "1";

        int zero_cnt = s.size()-cnt;

        for(int i=1;i<=zero_cnt;i++)
        ans = ans + "0";

        ans = ans + "1";

        return ans;

    }
};