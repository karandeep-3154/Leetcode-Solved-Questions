class Solution {
public:
    int minDeletions(string ss) {
        
        map<int, int> a;
        set<int> s;

        for(auto i : ss)
        a[i]++;

        int cnt=0;

        for(auto i : a){

            if(s.count(i.second) == 0)
            s.insert(i.second);

            else{

                int val = i.second;

               while(s.count(val) and val>0){

                   cnt++;
                   val--;

               }

               if(val>0 and s.count(val)==0)
               s.insert(val); 

            }

        }

        return cnt;

    }
};