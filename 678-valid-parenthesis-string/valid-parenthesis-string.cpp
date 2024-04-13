class Solution {
public:
    bool checkValidString(string s) {

        int n = s.size();
        
        stack<int> opening, asterisk;

        for(int i=0;i<n;i++){

            if(s[i] == '(')
            opening.push(i);

            else if(s[i] == ')'){

                if(opening.size())
                opening.pop();

                else if(asterisk.size())
                asterisk.pop();

                else
                return false;

            }

            else if(s[i] == '*')
            asterisk.push(i);

        }

        if(asterisk.size()<opening.size())
        return false;

        while(opening.size()){

            if(opening.top()>asterisk.top())
            return false;

            opening.pop();
            asterisk.pop();

        }

        return true;

    }
};