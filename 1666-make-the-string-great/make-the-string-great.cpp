class Solution {
public:
    string makeGood(string s) {
        
        stack<char> st;

        for(auto i : s){

            if(isupper(i)){

                if(st.size() and islower(st.top())){

                    char ch = tolower(i);
                    
                    if(ch == st.top())
                    st.pop();
                    
                    else
                    st.push(i);

                }

                else
                st.push(i);

            }

            else{

                if(st.size() and isupper(st.top())){

                    char ch = tolower(st.top());
                    
                    if(ch == i)
                    st.pop();
                    
                    else
                    st.push(i);

                }

                else
                st.push(i);

            }


        }

        string ans = "";
        
        while(st.size()){

            ans.push_back(st.top());
            st.pop();

        }

        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};