class Solution {
public:
    int numWaterBottles(int a, int b) {
        int cnt = 0;
        int e = 0;
        while(a>0){
            cnt += a;
            e += a;
            a = e/b;
            e = e%b;
        }

        return cnt;
    }
};