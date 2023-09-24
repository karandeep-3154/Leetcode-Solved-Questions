class Solution {
public:
    void find(vector<int>&A,vector<long long>&pref){
        stack<pair<long long,int>>P;
        int n = A.size();
        
        for(int i=0;i<n;++i){
               
           if(i == 0){
               pref[i] = A[i];
               P.push({A[i],i});
           } 
            else{
                while(A[i] < P.top().first){
                    P.pop();
                    if(P.empty())break;
                }
                if(P.empty()){
                    pref[i] = A[i];
                    long long z = i;
                    z++;
                    pref[i]*=(z);
                }
                else{
                    pref[i] = pref[P.top().second];
                    long long z = (i-P.top().second);
                    long long val = A[i];
                    val *= z;
                    pref[i] += val;
                    
                }
                P.push({A[i],i});
            }
        }
    }
    long long maximumSumOfHeights(vector<int>& A) {
        
        int n = A.size();
        vector<long long>pref(n),suff(n);
        
        
        find(A,pref);
        reverse(A.begin(),A.end());
        find(A,suff);
        reverse(suff.begin(),suff.end());
        reverse(A.begin(),A.end());
        
        long long ans = 0;
        for(int i=0;i<n;++i){
            
            long long val = A[i];
            val = (pref[i] + suff[i])-val;
            ans = max(ans,val);
        }
        
        
        return ans;
    }
};