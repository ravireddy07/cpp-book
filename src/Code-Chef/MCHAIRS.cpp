#include <cstdio>
#include <vector>

int main(){

    const long long MOD = 1000000007;
    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        long long res(1);
        std::vector<bool> b;
        while(n > 0){b.push_back(n % 2); n /= 2;}
        for(int p = b.size() - 1; p >= 0; p--){
            res = res * res;
            if(b[p]){res *= 2;}
            res %= MOD;
        }

        res = (res + MOD - 1) % MOD;
        printf("%lld\n", res);
    }

    return 0;
}
