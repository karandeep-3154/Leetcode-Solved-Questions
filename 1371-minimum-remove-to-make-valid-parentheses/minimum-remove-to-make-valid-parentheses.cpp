class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> st;
        int n = s.size();

        vector<int> v(n, 0);

        for(int i=0;i<n;i++){

            if(s[i] == '(')
            st.push(i);

            else if(s[i] == ')'){

                if(st.size())
                st.pop();

                else
                v[i] = 1;

            }

        }

        while(st.size()){

            v[st.top()] = 1;
            st.pop();

        }

        string ans = "";
        for(int i=0;i<n;i++)
            if(v[i] == 0)
            ans.push_back(s[i]);

        return ans;

    }
};