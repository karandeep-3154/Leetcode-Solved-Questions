class Solution {
public:
//REFER https://www.youtube.com/watch?v=CsK02Hi796U

    string merge(string a, string b){

        if(a.find(b) != string::npos)
        return a;

        if(b.find(a) != string::npos)
        return b;

        for(int i=min(a.size(), b.size());i>=1;i--){

            if(a.substr(a.size()-i) == b.substr(0, i))
            return a + b.substr(i);

        }

        return a+b;

    }

    void getMinString(string &res, string cur){

        string ans = res;

        if(res == "" or cur.size() < res.size() or (cur.size() == res.size() and cur<res))
        ans = cur;

        res = ans;

    }

    string minimumString(string a, string b, string c) {
        
        string res = "";

        vector<string> arr = {a,b,c};

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){

                    if(i!=j and j!=k and i!=k){
cout<<i<<j<<k<<endl;
                        string new1 = merge(arr[i], arr[j]);
                        cout<<new1<<"   ";
                        string new2 = merge(new1, arr[k]);
                        cout<<new2<<"   ";

                        getMinString(res, new2);
                        cout<<res<<endl;

                    }

                }
            }
        }

        return res;

    }
};