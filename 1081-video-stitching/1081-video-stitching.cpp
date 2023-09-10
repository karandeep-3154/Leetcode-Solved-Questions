class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b){

        if(a[0]!=b[0])
        return a[0]<b[0];

        return a[1]>b[1];

    }

    int videoStitching(vector<vector<int>>& clips, int time) {
        
        sort(clips.begin(), clips.end(), cmp);

        int last = clips[0][1], cnt = 1;

        if(clips[0][0]>0)
        return -1;

        for(int i=0;i<clips.size();){

            if(last>=time)
            return cnt;

            int newlast = last;
            int j = i+1, newi=-1;

            for(;j<clips.size();j++){

                if(clips[j][1]<=last)
                continue;

                if(clips[j][0]<=last){
                
                    if(clips[j][1]>newlast){

                        newlast = clips[j][1];
                        newi = j;

                    }
                
                }

            }

            if(newlast >last){

                last = newlast;
                i=newi;
                cnt++;

            }

            else
            return -1;

        }

        return last>=time ? cnt : -1;

    }
};