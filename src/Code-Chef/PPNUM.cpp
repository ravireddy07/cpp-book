#include <cstdio>
#include <iostream>

int main(){

    const long long MOD = 1000000007;
    const int N = 10;
    int t; scanf("%d\n", &t);
    while(t--){
        long long a, b; scanf("%lld %lld\n", &a, &b);
        long long pow(1);
        int numDigits(1);
        long long total(0);
        for(int p = 1; p < N; p++){
            long long s = (a > pow) ? a : pow;
            long long f = (b < (10 * pow - 1)) ? b : (10 * pow - 1);
            if(s <= f){total += (numDigits * ((f * (f + 1) / 2 - s * (s - 1) / 2)) % MOD) % MOD;}
            pow *= 10; ++numDigits;
        }
        printf("%lld\n", total);
    }

    return 0;
}
