class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int ce=0;

        for(auto i : logs){

            if(i == "./")
            continue;

            else if(i == "../" ){
                if(ce>0)
                    ce--;
            }

            else
            ce++;

        }

        return abs(ce);

    }
};