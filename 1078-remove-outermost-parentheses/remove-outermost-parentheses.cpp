class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int cnt = 0;

        string ans = "";

        for(auto i : s){

            if(i == '(')
            cnt++;

            else
            cnt--;

            if((i=='(' and cnt>1) or (i == ')' and cnt>=1))
            ans += i;

        }

        return ans;

    }
};