class Solution {
public:
    int scoreOfString(string s) {
        vector<int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp.push_back(s[i]);
        }
        int sum=0;
        for(int i=0;i<mp.size()-1;i++)
        {
            sum=sum+abs(mp[i]-mp[i+1]);
            
        }
        return sum;
    }
};