class Solution {
public:
    string reversePrefix(string word, char ch) {
        int chIndex = word.find(ch);
        if (chIndex == -1) {
            return word;
        }

        string result;

        for (int i = 0; i < word.length(); i++) {
            // Add characters through ch to the result in reverse order
            if (i <= chIndex) {
                result += word[chIndex - i];
            }
            // Add the rest of the characters to result
            else {
                result += word[i];
            }
        }

        return result;
    }
};