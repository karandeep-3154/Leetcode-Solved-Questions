class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        map<char,int> s;

        for(auto i : words[0])
        s[i]++;

        for(auto i : words){

            map<char, int> mp;

            for(auto j : i)
            mp[j]++;

            for(auto k : s){

                if(mp.find(k.first) == mp.end())
                s[k.first] = 0;

                else
                s[k.first] = min(k.second, mp[k.first]);

            }
        }
        
        vector<string> ans;

        for(auto i : s){
            for(int j=0;j<i.second;j++){
            string ss(1,i.first);
            ans.push_back(ss);}
        }

        return ans;

    }
};