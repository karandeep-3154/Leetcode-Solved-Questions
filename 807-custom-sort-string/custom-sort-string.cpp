class Solution {
public:
    string customSortString(string order, string s) {
        
        int present[26] = {0};

        for(auto i : s)
        present[i-'a']++;

        string ans = "";

        for(auto i : order){

            if(present[i-'a']){

                int cnt = present[i-'a'];

                while(cnt--)
                ans.push_back(i);

                present[i-'a'] = 0;
            }

        }

        for(int i=0;i<26;i++){

            if(present[i]){
            
                int cnt = present[i];

                while(cnt--)
                ans.push_back(char(i+'a'));
                
            }
        }

        return ans;

    }
};