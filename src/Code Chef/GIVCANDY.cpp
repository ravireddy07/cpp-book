#include<cstdio>

long long gcd(long long a, long long b){return (a == 0) ? b : gcd(b % a, a);}

int main(){

    long t; scanf("%ld", &t);
    while(t--){
        long long a, b, c, d; scanf("%lld %lld %lld %lld\n", &a, &b, &c, &d);
        long long f = (a < b) ? (b - a) : (a - b);
        long long g = gcd(c, d);
        f %= g;
        long long ans = (f < g - f) ? f : (g - f);
        printf("%lld\n", ans);
    }
    
    return 0;
}
