class Solution {
public:

    int compareVersion(string version1, string version2) {
        
        int i=0, j=0, m=version1.size(), n=version2.size();

        vector<int> v1, v2;

        while(i<m){

            if(version1[i] == '.' or i == m-1){
                
                int len = 0;

                if(i == m-1)
                len = i-j+1;

                else
                len = i-j;

                v1.push_back(stoi(version1.substr(j, len)));
                j=i+1;
            }

            i++;

        }

        i=0;
        j=0;

        while(i<n){
            
            if(version2[i] == '.' or i==n-1){

               int len = 0;
                
                if(i == n-1)
                len = i-j+1;

                else
                len = i-j;

                v2.push_back(stoi(version2.substr(j, len)));
                j=i+1;
            }

            i++;

        }

        i=0;
        int mm = v1.size(), nm = v2.size();

        while(i<max(mm, nm)){

            int s1 = (i<mm ? v1[i] : 0);
            int s2 = (i<nm ? v2[i] : 0);

            if(s1<s2)
            return -1;

            else if(s1>s2)
            return 1;

            i++;j++;

        }

        return 0;

    }
};