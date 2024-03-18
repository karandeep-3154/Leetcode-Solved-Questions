class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.length();
        int freq[26] = {0};
        for (char ch : s)
            if (ch != '?')
                freq[ch - 'a']++;
        vector<char> chars;
        for (int i = 0; i < n; i++)
            if (s[i] == '?') {
                int indexOfMinElement = 0;
                for (int j = 0; j < 26; j++)
                    if (freq[j] < freq[indexOfMinElement])
                        indexOfMinElement = j;
                char chh = indexOfMinElement + 'a';
                chars.push_back(chh);
                freq[indexOfMinElement]++;
            }
        sort(chars.begin(), chars.end());
        int j = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '?')
                s[i] = chars[j++];
        return s;
    }
};