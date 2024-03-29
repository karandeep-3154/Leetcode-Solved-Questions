class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;

        if(digits.size() == 0)
        return ans;

        vector<string> chars = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if(digits.size() == 1){

            for(auto c : chars[(int)digits[0] - (int)'0']){
                
                string s(1, c);
                ans.push_back(s);
            
            }

            return ans;

        }

        for(auto c: chars[(int)digits[0] - (int)'0']){

            vector<string> next = letterCombinations(digits.substr(1));
            string s(1, c);
            
            for(auto i : next)
            ans.push_back(s+i);

        }
        
        return ans;

    }
};