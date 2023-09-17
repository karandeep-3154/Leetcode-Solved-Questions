class Solution {
public:

    int minLengthAfterRemovals(vector<int>& nums) {
        
        unordered_map<int, int> mp;

        for(auto i : nums)
        mp[i]++;

        priority_queue<int> pq;

        for(auto i : mp)
        pq.push(i.second);

        while(pq.size()>1){

            int top1 = pq.top();
            pq.pop();

            int top2 = pq.top();
            pq.pop();

            if(top1-1>0)
            pq.push(top1-1);

            if(top2-1>0)
            pq.push( top2-1);


        }

        if(pq.size())
        return pq.top();

        return 0;

    }
};