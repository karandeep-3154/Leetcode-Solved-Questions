class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        map<char, set<char>> mp;

        set<char> s;

        for(auto i : order){

            mp[i] = s;
            s.insert(i);

        }
        
        for(int i=1;i<words.size();i++){

            string prev = words[i-1], cur = words[i];
            bool flag = false;

            for(int j=0;j<min(prev.size(), cur.size());j++){

                if(prev[j] == cur[j])
                continue;

                flag = true;
                if(mp[cur[j]].count(prev[j]) == 0)
                return false;

                break;

            }

            if(flag == false and prev.size()>cur.size())
            return false;

        }

        return true;

    }
};