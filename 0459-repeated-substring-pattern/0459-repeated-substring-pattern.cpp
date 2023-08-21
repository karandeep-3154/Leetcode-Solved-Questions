class Solution {
public:

    bool check(string a, string b){

        if(b.size()%a.size())
        return false;

        int p=b.size()/a.size();

        string s="";

        while(p--)
        s+=a;

        return s==b;

    }

    bool repeatedSubstringPattern(string s) {

        // if(s.size() <= 1)
        // return true;
        
        for(int i=0;i<s.size()/2;i++){
            if(check(s.substr(0,i+1),s))
            return true;
        }

        return false;

    }
};