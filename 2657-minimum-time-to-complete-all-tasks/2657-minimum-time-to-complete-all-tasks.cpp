class Solution {
public:
//  REFER https://www.youtube.com/watch?v=yw9l_BXKpno

    static bool cmp(vector<int> &a, vector<int> &b){

        return a[1]<b[1];

    }

    int findMinimumTime(vector<vector<int>>& tasks) {
        
        sort(tasks.begin(), tasks.end(), cmp);//sorting on the basis of end point because we want to check for element which ends first so that it can tackle start of some other element just remove cmp from here and dry run for case 1 of given testcase and u will understand this in detail

        int n = tasks.size();

        vector<int> is_filled(tasks[n-1][1]+1, 0);

        for(auto i : tasks){

            int low = i[0], high = i[1], cnt = i[2];

            for(int j=low;j<=high and cnt>0;j++)
            if(is_filled[j] == 1)
            cnt--;

            if(cnt == 0)
            continue;

            int j=high;
            while(cnt>0 and j>=low){

                if(is_filled[j] == 0){

                    is_filled[j] = 1;
                    cnt--;

                }

                j--;

            }

        }

        int sum=0;
        sum = accumulate(is_filled.begin(), is_filled.end(), sum);

        for(auto i : is_filled)cout<<i<<endl;
 
        return sum;

    }
};