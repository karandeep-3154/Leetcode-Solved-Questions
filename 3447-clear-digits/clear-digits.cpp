class Solution {
public:
    string clearDigits(string s) {
        
        int cnt = 0;
        string ans = "";
        
        for(int i=s.size()-1;i>=0;i--){

            if(isdigit(s[i]))
            cnt++;

            else{

                if(cnt)
                cnt--;

                else
                ans.push_back(s[i]);

            }

        }

        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};