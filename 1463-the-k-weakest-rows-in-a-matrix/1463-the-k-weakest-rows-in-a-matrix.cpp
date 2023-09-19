class Solution {
public:

    static bool cmp(vector<int> &a, vector<int>& b){

        if(a[0] != b[0])
        return a[0]<b[0];

        return a[1]<b[1];

    }

    int find_cnt(vector<int> &v){

        int n=v.size(), low=0, high = n-1, ans=n;

        while(low<=high){

            int mid = (low + high)/2;

            if(v[mid] == 0){

                ans = mid;
                high = mid-1;

            }

            else
            low = mid+1;

        }

        return ans;

    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int kk) {
        
        vector<vector<int>> v;
        int k=0, i=0;

        for(auto i : mat){

            int cnt = find_cnt(i);

            v.push_back({cnt, k++});

        }

        sort(v.begin(), v.end(), cmp);

        vector<int> ans;

        while(i<kk)
        ans.push_back(v[i++][1]);

        return ans;

    }
};