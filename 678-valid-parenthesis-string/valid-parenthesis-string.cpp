class Solution {
public: 
    bool checkValidString(string s) {
        int n = s.size();
        // dp[index][openBracket] represents if the substring starting from index i is valid with j opening brackets
        vector<vector<bool>> dp(n + 1, vector<bool> (n + 1, false));
        // base case: an empty string with 0 opening brackets is valid
        dp[n][0] = true;

        for (int index = n - 1; index >= 0; index--) {
            for (int openBracket = 0; openBracket <= n; openBracket++) {
                bool isValid = false;

                // '*' can represent '(' or ')' or '' (empty)
                if (s[index] == '*') {
                    isValid |= dp[index + 1][openBracket + 1]; // try '*' as '('

                    // opening brackets to use '*' as ')'
                    if (openBracket > 0) {
                        isValid |= dp[index + 1][openBracket - 1]; // try '*' as ')'
                    }
                    isValid |= dp[index + 1][openBracket]; // ignore '*'
                } else {
                    // If the character is not '*', it can be '(' or ')'
                    if (s[index] == '(') {
                        isValid |= dp[index + 1][openBracket + 1]; // try '('
                    } else if (openBracket > 0) {
                        isValid |= dp[index + 1][openBracket - 1]; // try ')'
                    }
                }
                dp[index][openBracket] = isValid;
            }
        }

        return dp[0][0]; // True if the entire string is valid with no excess opening brackets
    }
};