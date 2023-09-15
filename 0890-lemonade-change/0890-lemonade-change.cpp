class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        map<int, int, greater<int>> mp;

        for(auto i : bills){

            if(i==5)
            mp[5]++;

            else{

                mp[i]++;

                int val = i-5;

                for(auto j : mp){

                    int cnt = val/j.first;
                    val = val - min(cnt, j.second)*j.first;

                    mp[j.first]-=min(cnt, j.second);

                    if(val == 0)
                    break;

                }

                if(val>0)
                return false;

            }

        }

        return true;

    }
};