class Solution {
public:
    
    int string_to_int(string s){
        int val=0;
        for(int i=0;i<s.length();i++) val = val*10 + (s[i]-'0');
        
        return val;
    }
    
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
		map<string, vector<int>> times;
        for(vector<string> v : access_times){
            string s=v[1];
            
            int minutes = string_to_int(s.substr(0,2))*60 + string_to_int(s.substr(2));
            times[v[0]].push_back(minutes);
        }
        
        vector<string> ans;
        for(auto it=times.begin();it!=times.end();it++){
            string ch = it->first;
            vector<int> time = it->second;
            
            vector<int> sweep(1441,0);
            for(int t : time){
				// contribution of each access for next 59 minutes
                sweep[t]++;
                if(t+60 < 1441) sweep[t+60]--;
            }
            
			// check for at least 3 overlapping access times
            int c=0;
            for(int i=0;i<1441;i++){
                c += sweep[i];
                
                if(c>=3){
                    ans.push_back(ch);
                    break;
                }
            }
        }
        
        return ans;
    }
};