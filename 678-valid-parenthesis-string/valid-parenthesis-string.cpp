class Solution {
public:
// REFER https://youtu.be/Pno2hATcwHA?si=1nY-uYZM1pyC-WbR 

    bool checkValidString(string s) {
        
        int open=0, close=0, n=s.size();

        for(int i=0;i<n;i++){

            if(s[i] == '(' or s[i] == '*')
            open++;

            else
            open--;

            if(open == -1){cout<<"pehla de rha hai false";
            return false;}

            int j = n-1-i;

            if(s[j] == ')' or s[j] == '*')
            close++;

            else
            close--;

            if(close == -1)
            return false;

        }

        return true;

    }
};