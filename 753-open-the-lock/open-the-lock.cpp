class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        
        set<string> deadend;
        for(auto i : deadends)
        deadend.insert(i);

        if(deadend.count("0000"))
        return -1;

        map<string, int> vis;
        vis["0000"] = 1;

        while(q.size()){

            string s = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(s == target)
            return steps;

            for(int i=0;i<4;i++){

                string ss = s, sss = s;
                if(ss[i] == '0')
                ss[i] = '9';
                else
                ss[i] = ss[i]-1;

                if(sss[i] == '9')
                sss[i] = '0';
                else
                sss[i] = sss[i]+1;

                if(vis.count(ss) == 0 and deadend.count(ss) == 0){
                
                    q.push({ss, steps+1});
                    vis[ss] = 1;
                
                }
                if(vis.count(sss) == 0 and deadend.count(sss) == 0){
                
                    q.push({sss, steps+1});
                    vis[sss] = 1;
                
                }

            }

        }

        return -1;

    }
};