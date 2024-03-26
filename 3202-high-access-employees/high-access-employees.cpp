class Solution {
public:

    pair<int, int> getTime(string s){

        int hr = stoi(s.substr(0, 2));
        int min = stoi(s.substr(2, 2));

        return {hr, min};

    }

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        
        map<string, vector<string>> mp;

        for(auto i : access_times)
        mp[i[0]].push_back(i[1]);

        vector<string> ans;

        for(auto i : mp){

            string emp = i.first;
            sort(i.second.begin(), i.second.end());

            vector<string> timings = i.second;

            if(timings.size()<3)
            continue;

            int a=0;
            // while(getTime(timings[a]).first == 0)
            // a++;

            int b = a+2;

            while(b<timings.size()){

                // if(getTime(timings[b]).first == 23)
                // break;

                auto [hr1, min1] = getTime(timings[a]);
                auto [hr2, min2] = getTime(timings[b]);

                if(hr1 == hr2 and min2-min1<60){
                    ans.push_back(emp);
                    break;
                }

                else if(hr2-hr1 == 1 and 60-min1 + min2<60){
                    ans.push_back(emp);
                    break;
                }

                a++;
                b++;

            }            

        }
        
        return ans;

    }
};