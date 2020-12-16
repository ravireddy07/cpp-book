#include <cstdio>

long gcd(long a, long b){return (a == 0) ? b : gcd(b % a, a);}

int main(){

    long t; scanf("%ld\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        long g(0);
        while(n--){
            long x; scanf("%ld", &x);
            g = gcd(g, x);
        }

        if(g > 1){
            long ans(g);
            for(long p = 2; p * p <= g; p++){if(g % p == 0){ans = p; break;}} 
            printf("%ld\n", ans);
        }
        else{puts("-1");}
    }

    return 0;
}
