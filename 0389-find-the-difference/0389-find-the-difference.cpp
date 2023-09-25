class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int a[26]={0};
        int b[26]={0};

        for(auto i : s)
        a[i-'a']++;

        for(auto i : t)
        b[i-'a']++;

        for(int i=0;i<26;i++)
        if(a[i]<b[i])
        return i+'a';

        return ' ';

    }
};