class Solution {
public:
    bool check(string i){
        return (i[0] == 'a' or i[0] == 'e' or i[0] == 'i' or i[0] == 'o' or i[0] == 'u') and (i[i.size()-1] == 'a' or i[i.size()-1] == 'e' or i[i.size()-1] == 'i' or i[i.size()-1] == 'o' or i[i.size()-1] == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        vector<int> ans(queries.size(),0),v(words.size(),0);
        int k=0;
        
        for(auto i : words){
            if(check(i)){
                if(k!=0)
                    v[k]=v[k-1]+1;
                else
                    v[k]=1;
            }
            else{
                if(k!=0)
                    v[k]=v[k-1];
                else
                    v[k]=0;
            }
                
       
            k++;
    }
        
        k=0;
        for(auto i : queries){
            
            int c = v[i[1]]-v[i[0]];

            if(check(words[i[0]])){
                cout<<"hi";
                c++;
            }

            ans[k++]=c;
            
        }
        return ans;
    }
};