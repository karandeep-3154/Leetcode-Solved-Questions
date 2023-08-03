class Solution {
public:

    void backtrack(string digits, int i, string cur, vector<string> &ans, unordered_map<char, vector<int>> mp){

        if(i == digits.size()){

            ans.push_back(cur);
            return;

        }

        for(auto j : mp[digits[i]]){

            cur.push_back(j);
            backtrack(digits, i+1, cur, ans, mp);
            cur.pop_back();

        }

    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        unordered_map<char, vector<int>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'u', 'v', 't'};
        mp['9'] = {'w', 'x', 'y', 'z'};

        backtrack(digits, 0, "", ans, mp);

        if(ans[0] == "")
        ans.pop_back();
        
        return ans;

    }
};