class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        int l=s.size();
        for(int i=0;i<l;i++){
            v[int(s[i])-97]+=1;
        }
        int maxx=0;

        for(int i=0;i<26;i++){
            maxx=max(maxx,v[i]);
        }
        vector<int> ar(maxx+1,0);
        for(int i=0;i<26;i++){
            ar[v[i]]+=v[i]>0?1:0;
        }
        int count=0;
        for(int i=maxx;i>=1;i--){
            
            if(ar[i]>1){
                count+=ar[i]-1;
                ar[i-1]+=ar[i]-1;
                ar[i]=1;
            }
            
        }    
        return count;                                                        
            
    }
};