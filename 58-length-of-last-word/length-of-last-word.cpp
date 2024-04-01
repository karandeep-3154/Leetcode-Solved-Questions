class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int a=0, b=-1, i=s.size()-1;

        while(i>=0){

            if(s[i]!=' ' and b == -1)
            b = i;

            else if(s[i] == ' ' and b!=-1){
                
                a = i+1;
                break;
            
            }

            i--;

        }

        return b-a+1;

    }
};