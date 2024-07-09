class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        long long t = 0, av = 0, n = customers.size();

        for(auto i : customers){

            long long ct = i[0], duration = i[1];

            if(ct >= t){
                t = ct + duration;
                av += duration;
            }

            else{
                av += t-ct + duration;
                t += duration;
            }

        }

        return av/(double)n;

    }
};