class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int s1=0, s2=0;

        for(auto i : s)
        s1+=(int)i;

        for(auto i : t)
        s2+=(int)i;

        return char(s2-s1);

    }
};