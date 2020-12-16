#include <cstdio>

int main(){

    const long long MOD = 1000000007;

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        long max(0), maxCount(0);
        while(n--){
            long a; scanf("%ld", &a);
            if(a > max){max = a; maxCount = 1;}
            else if(a == max){++maxCount;}
        }

        long long ans(1);
        for(long p = 0; p < maxCount; p++){ans *= 2; ans %= MOD;}
        ans = (ans + MOD - 1) % MOD;
        printf("%lld\n", ans);
    }

    return 0;
}
