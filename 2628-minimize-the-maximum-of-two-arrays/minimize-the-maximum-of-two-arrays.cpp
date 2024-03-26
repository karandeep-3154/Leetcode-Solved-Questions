class Solution {
public:

// REFER https://youtu.be/cuNS7HcvWoQ?si=GTm7V4w8vUune_zn

    bool check(int p, int d1, int d2, int u1, int u2){

        long long lcm = (1LL*d1*d2)/__gcd(d1, d2);
        long long a = p-(p/d1), b = p-(p/d2), c = p-(p/d1)-(p/d2)+(p/lcm);
// cout<<"a is "<<a<<"  b is "<<b<<"  c is "<<c<<lcm<<endl;
        return a>=u1 and b>=u2 and a+b-c>=u1+u2;

    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        
        long long l=1, h=1e17, ans=1e17;

        while(l<=h){

            long long mid = (l+h)/2;

            if(check(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)){

                if(ans>mid)
                ans = mid;

                h = mid-1;
            
            }

            else
            l = mid+1;

        }

        return ans;

    }
};