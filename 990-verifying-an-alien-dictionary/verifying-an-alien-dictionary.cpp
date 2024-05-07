class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        map<char, int> mp;

        for(int i=0;i<order.size();i++)
        mp[order[i]] = i;

        for(int i=1;i<words.size();i++){

            string prev = words[i-1], cur = words[i];
            bool flag = false;

            for(int j=0;j<min(prev.size(), cur.size());j++){

                if(prev[j] == cur[j])
                continue;

                flag = true;
                if(mp[cur[j]] < mp[prev[j]])
                return false;

                break;

            }

            if(flag == false and prev.size()>cur.size())
            return false;

        }

        return true;

    }
};