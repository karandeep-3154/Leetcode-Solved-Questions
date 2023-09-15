class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> st, left;

        for(int i=0;i<s.size();i++){

            if(s[i] == '(')
            left.push(i);

            else if(s[i] == '*')
            st.push(i);

            else{

                if(left.size())
                left.pop();

                else if(st.size())
                st.pop();                

                else
                return false;

            }

        }

        while(st.size() and left.size()){

            if(st.top()>left.top()){

                st.pop();
                left.pop();

            }

            else
            st.pop();

        }

        return left.size() == 0;

    }
};