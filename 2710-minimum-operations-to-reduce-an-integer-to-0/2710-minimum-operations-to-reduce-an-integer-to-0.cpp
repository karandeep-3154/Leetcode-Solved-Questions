class Solution {
public:
    int minOperations(int n) {
        // __builtin_popcount()
        // int ms=log2(n); 
        int adding_op=0;
        for (int i=0;i<20;i++){
            if (__builtin_popcount(n+(1<<i))< __builtin_popcount(n)){
                adding_op++;
                n+=(1<<i);
            }
        }
        int sub_op = __builtin_popcount(n);
        return adding_op+sub_op;
    }
};