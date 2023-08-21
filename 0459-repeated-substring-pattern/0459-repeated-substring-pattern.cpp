class Solution {
public:

    // The idea behind this approach is that if a string s can be constructed by repeating a substring, then concatenating two copies of s together and removing the first and last character would still contain s as a substring.

    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        string sub = doubled.substr(1, doubled.size() - 2);
        return sub.find(s) != string::npos;
    }

};