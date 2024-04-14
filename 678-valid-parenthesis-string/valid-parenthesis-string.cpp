class Solution {
public:
// REFER https://youtu.be/Pno2hATcwHA?si=1nY-uYZM1pyC-WbR 

    bool checkValidString(string s) {
        
        int open=0, close=0;

        for(auto i : s){

            if(i == '(' or i == '*')
            open++;

            else
            open--;

            if(open == -1)
            return false;

        }

        for(int i=s.size()-1;i>=0;i--){            

            if(s[i] == ')' or s[i] == '*')
            close++;

            else
            close--;

            if(close == -1)
            return false;

        }

        return true;

    }
};