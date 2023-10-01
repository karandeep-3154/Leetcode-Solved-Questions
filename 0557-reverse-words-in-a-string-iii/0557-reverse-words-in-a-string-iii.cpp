class Solution {
public:
    string reverseWords(string s) {
        
        string news="";
        s+=" ";

        int i=0;

        for(int j=0;j<s.size();j++){

            if(s[j] == ' '){
                string p = s.substr(i,j-i);
                reverse(p.begin(), p.end());
                if(j==s.size()-1)
                news+=p;
                else
                news = news + p + " ";
                i=j+1;
            }

        }

        return news;

    }
};