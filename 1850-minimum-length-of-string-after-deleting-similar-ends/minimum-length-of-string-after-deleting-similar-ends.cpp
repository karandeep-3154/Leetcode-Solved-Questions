class Solution {
public:
    int minimumLength(string s) {
        
        int i=0, j=s.size()-1;
        char first=s[0], last=s[j];

        while(i<j){

            cout<<i<<" j is "<<j<<endl;

            if(first!=last)
            return j-i+1;

            int ii=i, jj=j;

            while(i<s.size() and s[i]==first)
            i++;

            if(i!=s.size())
            first = s[i];

            while(j>=0 and s[j]==last)
            j--;

            if(j!=-1)
            last = s[j];

            if(i == -1 or j==-1){

                if((jj-ii+1)%2 == 0)
                return 1;

                else
                return 0;
                
            }

        }

        return i == j ? 1 : 0;

    }
};